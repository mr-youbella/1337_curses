#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <vector>
#include <map>
#include <set>
#include <poll.h>
#include "client.hpp"
#include "channel.hpp"
#include "command_handler.hpp"

class Server
{
	private:
		int								_listen_fd;
		int								_port;
		std::string						_password;
		std::vector<struct pollfd>		_poll_fds;
		std::map<int, Client>			_clients;
		std::map<std::string, Channel>	_channel;
		std::set<int>					_closing_clients;
		CommandHandler					_command_handler;

		Server();
		Server(const Server &other);
		Server					&operator=(const Server &other);

		void setupSocket();
		void acceptClient();
		void handleClientRead(int fd);
		void handleClientWrite(int fd);
		void disconnectClient(int fd);
		void dispatchLine(Client &client, const std::string &line);
		void setNonBlocking(int fd);
		void flagWriteClients();

	public:
		Server(int port, const std::string &password);
		~Server();

		void							run();
		std::map<std::string, Channel>	&getChannels();
		Channel							*getChannel(const std::string &name);
		Channel							*create_channel(const std::string &name);
		void							removeEmptyChannel(const std::string &name);
		std::map<int, Client>			&getClients();
		bool							is_exist_nick(const std::string &nick);
};

#endif
