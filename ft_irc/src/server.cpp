#include "../inc/server.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cerrno>
#include <csignal>

Server::Server(int port, const std::string &password) : _listen_fd(-1), _port(port), _password(password), _command_handler(password)
{
	_command_handler.setServer(this);
	setupSocket();
}

Server::~Server()
{
	for (size_t i = 0; i < _poll_fds.size(); i++)
		close(_poll_fds[i].fd);
}

void Server::setNonBlocking(int fd)
{
	if (fcntl(fd, F_SETFL, O_NONBLOCK) == -1)
	{
		std::cerr << "fcntl failed\n";
		std::exit(1);
	}
}

void Server::setupSocket()
{
	if (std::signal(SIGPIPE, SIG_IGN) == SIG_ERR)
	{
		std::cerr << "failed to ignore SIGPIPE\n";
		std::exit(1);
	}

	_listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_listen_fd == -1)
	{
		std::cerr << "socket failed\n";
		std::exit(1);
	}

	int opt = 1;
	setsockopt(_listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	struct sockaddr_in addr;
	std::memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(_port);

	if (bind(_listen_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
	{
		std::cerr << "bind failed\n";
		std::exit(1);
	}

	if (listen(_listen_fd, SOMAXCONN) == -1)
	{
		std::cerr << "listen failed\n";
		std::exit(1);
	}

	setNonBlocking(_listen_fd);

	struct pollfd pfd;
	pfd.fd = _listen_fd;
	pfd.events = POLLIN;
	pfd.revents = 0;
	_poll_fds.push_back(pfd);

	std::cout << "server listening on port " << _port << '\n';
}

void Server::flagWriteClients()
{
	for (size_t i = 0; i < _poll_fds.size(); i++)
	{
		if (_poll_fds[i].fd == _listen_fd)
			continue;
		Client &client = _clients[_poll_fds[i].fd];
		if (client.hasDataToWrite())
			_poll_fds[i].events = POLLIN | POLLOUT;
		else
			_poll_fds[i].events = POLLIN;
	}
}

void Server::run()
{
	while (true)
	{
		int ready = poll(&_poll_fds[0], _poll_fds.size(), -1);
		if (ready == -1)
		{
			if (errno == EINTR)
				continue;
			std::cerr << "poll error: " << strerror(errno) << "\n";
			break;
		}

		std::vector<struct pollfd> snapshot = _poll_fds;

		for (size_t i = 0; i < snapshot.size(); i++)
		{
			int fd = snapshot[i].fd;
			short revents = snapshot[i].revents;

			if (fd != _listen_fd && _clients.find(fd) == _clients.end())
				continue;

			if (revents & POLLIN)
			{
				if (fd == _listen_fd)
					acceptClient();
				else
					handleClientRead(fd);
			}
			if ((revents & POLLOUT) && _clients.find(fd) != _clients.end())
				handleClientWrite(fd);
			if ((revents & (POLLHUP | POLLERR)) && _clients.find(fd) != _clients.end())
				disconnectClient(fd);
		}

		flagWriteClients();
	}
}

void Server::acceptClient()
{
	const int client_fd = accept(_listen_fd, NULL, NULL);
	if (client_fd == -1)
		return;

	setNonBlocking(client_fd);

	struct pollfd pfd;
	pfd.fd = client_fd;
	pfd.events = POLLIN;
	pfd.revents = 0;
	_poll_fds.push_back(pfd);

	_clients[client_fd] = Client(client_fd);

	std::cout << "client connected, fd " << client_fd << '\n';
}

void Server::handleClientRead(int fd)
{
	char buffer[1024];
	const int bytes_read = recv(fd, buffer, sizeof(buffer), 0);

	if (bytes_read <= 0)
	{
		disconnectClient(fd);
		return;
	}

	Client &client = _clients[fd];
	if (!client.appendToReadBuffer(buffer, bytes_read))
	{
		client.appendToWriteBuffer("ERROR :Input line too long\r\n");
		_closing_clients.insert(fd);
		return;
	}

	while (client.hasCompleteLine())
	{
		std::string line = client.extractLine();
		if (!line.empty())
		{
			dispatchLine(client, line);
			if (_command_handler.shouldDisconnect())
				break;
		}
	}
}

void Server::handleClientWrite(int fd)
{
	Client &client = _clients[fd];
	if (!client.hasDataToWrite())
		return;

	const std::string &data = client.getWriteBuffer();
	const int bytes_sent = send(fd, data.c_str(), data.size(), 0);

	if (bytes_sent > 0)
	{
		client.eraseWriteBuffer(bytes_sent);
		if (!client.hasDataToWrite() && _closing_clients.find(fd) != _closing_clients.end())
		{
			disconnectClient(fd);
			return;
		}
	}
}

void Server::dispatchLine(Client &client, const std::string &line)
{
	_command_handler.execute(client, line);
	if (_command_handler.shouldDisconnect())
		_closing_clients.insert(client.getFd());
}

void Server::disconnectClient(int fd)
{
	_closing_clients.erase(fd);
	std::map<int, Client>::iterator it = _clients.find(fd);
	if (it != _clients.end())
	{
		Client *client = &it->second;

		std::string quitMsg = ":" + client->getNickname() + "!" + client->getUsername() + "@localhost QUIT :Disconnected\r\n";

		for (std::map<std::string, Channel>::iterator cit = _channel.begin(); cit != _channel.end();)
		{
			Channel &chan = cit->second;
			if (chan.has_client(client))
			{
				std::vector<Client *> &members = chan.getClients();
				for (size_t i = 0; i < members.size(); i++)
				{
					if (members[i] != client)
						members[i]->appendToWriteBuffer(quitMsg);
				}
				chan.remove_client(client);
			}
			if (chan.has_operator(client))
				chan.remove_operator(client);
			if (chan.has_invited(client))
				chan.remove_invited(client);
			if (chan.isEmpty())
				_channel.erase(cit++);
			else
				cit++;
		}
	}

	close(fd);
	_clients.erase(fd);

	for (size_t i = 0; i < _poll_fds.size(); i++)
	{
		if (_poll_fds[i].fd == fd)
		{
			_poll_fds.erase(_poll_fds.begin() + i);
			break;
		}
	}
	std::cout << "client disconnected, fd " << fd << '\n';
}

std::map<std::string, Channel> &Server::getChannels()
{
	return (_channel);
}

Channel *Server::getChannel(const std::string &name)
{
	std::map<std::string, Channel>::iterator iter = _channel.find(name);
	if (iter == _channel.end())
		return NULL;
	return &(iter->second);
}

Channel *Server::create_channel(const std::string &name)
{
	Channel *name_channel;
	name_channel = getChannel(name);
	if (name_channel == NULL)
	{
		_channel.insert(std::make_pair(name, Channel(name)));
		return (getChannel(name));
	}
	else
		return name_channel;
}

void Server::removeEmptyChannel(const std::string &name)
{
	std::map<std::string, Channel>::iterator it = _channel.find(name);
	if (it != _channel.end() && it->second.isEmpty())
		_channel.erase(it);
}

std::map<int, Client> &Server::getClients()
{
	return _clients;
}

bool Server::Exist_nick(const std::string &nick)
{
	for (std::map<int, Client>::iterator it = _clients.begin(); it != _clients.end(); it++)
	{
		if (it->second.getNickname() == nick)
			return true;
	}
	return false;
}
