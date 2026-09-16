#include "../inc/command_handler.hpp"
#include "../inc/server.hpp"
#include "../inc/channel.hpp"
#include <cctype>
#include <iostream>
#include <sstream>

CommandHandler::CommandHandler(std::string const &password) : _password(password), _server(NULL), _should_disconnect(false), _bot("IRCBot"), _fileTransfer() {}

CommandHandler::~CommandHandler() {}

void CommandHandler::setServer(Server *server)
{
	_server = server;
}

bool CommandHandler::shouldDisconnect() const
{
	return _should_disconnect;
}

static std::string getCommand(std::string const &line)
{
	size_t pos = line.find(' ');
	if (pos == std::string::npos)
		return (line);
	return (line.substr(0, pos));
}

static std::string getParam(std::string const &line)
{
	size_t pos = line.find(' ');
	if (pos == std::string::npos)
		return ("");
	std::string param = line.substr(pos + 1);
	if (!param.empty() && param[0] == ':')
		param = param.substr(1);
	return (param);
}

void CommandHandler::handlePing(Client &client, const std::string &param)
{
	if (param.empty())
	{
		client.appendToWriteBuffer(":IRCServer 409 * :No origin specified\r\n");
		return;
	}
	client.appendToWriteBuffer("PONG :" + param + "\r\n");
}

void CommandHandler::handleQuit(Client &client)
{
	client.appendToWriteBuffer("ERROR :Closing connection\r\n");
	_should_disconnect = true;
}

void CommandHandler::handlePass(Client &client, const std::string &param)
{
	parse input;
	std::string mutableParam = param;
	if (client.isRegistered())
	{
		client.appendToWriteBuffer(":IRCServer 462 " + client.getNickname() + " :You may not reregister\r\n");
		return;
	}
	if (!input.PASS(mutableParam, _password))
	{
		client.appendToWriteBuffer(":IRCServer 464 * :Password incorrect\r\n");
		return;
	}
	client.setPassed(true);
}

void CommandHandler::handleNick(Client &client, const std::string &param)
{
	parse input;
	std::string mutableParam = param;
	if (!client.get_Passed())
	{
		client.appendToWriteBuffer(":IRCServer 451 * :You have not registered\r\n");
		return;
	}
	if (!input.NICK(mutableParam))
	{
		client.appendToWriteBuffer(":IRCServer 431 * :No nickname given\r\n");
		return;
	}
	if (_server->is_exist_nick(param) && param != client.getNickname())
	{
		client.appendToWriteBuffer(":IRCServer 433 * " + param + " :Nickname is already exist\r\n");
		return;
	}
	std::string oldNick = client.getNickname();
	client.setNickname(param);
	client.set_hasNickname(true);
	if (client.isRegistered() && !oldNick.empty() && oldNick != param)
	{
		std::string nickMsg = ":" + oldNick + "!" + client.getUsername() + "@localhost NICK :" + param + "\r\n";
		std::vector<Client *> notified;
		std::map<std::string, Channel> &channels = _server->getChannels();
		for (std::map<std::string, Channel>::iterator it = channels.begin(); it != channels.end(); ++it)
		{
			if (!it->second.has_client(&client))
				continue;
			std::vector<Client *> &members = it->second.getClients();
			for (size_t i = 0; i < members.size(); i++)
			{
				if (std::find(notified.begin(), notified.end(), members[i]) == notified.end())
				{
					members[i]->appendToWriteBuffer(nickMsg);
					notified.push_back(members[i]);
				}
			}
		}
	}
}

void CommandHandler::handleUser(Client &client, const std::string &param)
{
	parse input;
	if (client.isRegistered())
	{
		client.appendToWriteBuffer(":IRCServer 462 " + client.getNickname() + " :You may not reregister\r\n");
		return;
	}
	if (!client.get_hasNickname() || !client.get_Passed())
	{
		client.appendToWriteBuffer(":IRCServer 451 * :You have not registered\r\n");
		return;
	}
	if (!input.USER(param, client))
	{
		client.appendToWriteBuffer(":IRCServer 461 * USER :Not enough parameters\r\n");
		return;
	}
	client.set_hasUsername(true);
	client.setRegistered(true);
	client.appendToWriteBuffer(":IRCServer 001 " + client.getNickname() + " :Welcome to the IRC server\r\n");
}

void CommandHandler::execute(Client &client, std::string const &line)
{
	_should_disconnect = false;
	parse input;
	std::string cmd = getCommand(line);
	std::string param = getParam(line);
	for (size_t i = 0; i < cmd.size(); i++)
		cmd[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(cmd[i])));

	std::cout << "fd " << client.getFd() << " cmd: " << cmd << " param: " << param << '\n';

	if (cmd == "PING")
		handlePing(client, param);
	else if (cmd == "QUIT")
		handleQuit(client);
	else if (cmd == "PASS")
		handlePass(client, param);
	else if (cmd == "NICK")
		handleNick(client, param);
	else if (cmd == "USER")
		handleUser(client, param);
	else if (cmd == "JOIN")
	{
		if (!client.isRegistered())
		{
			client.appendToWriteBuffer(":IRCServer 451 * :You have not registered\r\n");
			return;
		}
		std::vector<std::string> channels;
		std::vector<std::string> keys;
		if (!input.JOIN_MULTI(param, channels, keys))
		{
			client.appendToWriteBuffer(":IRCServer 461 * JOIN :Not enough parameters\r\n");
			return;
		}
		if (_server)
		{
			for (size_t index = 0; index < channels.size(); index++)
			{
				const std::string &channel = channels[index];
				std::string key;
				if (index < keys.size())
					key = keys[index];
				Channel *chan = _server->create_channel(channel);
				if (chan->getInviteOnly() && !chan->has_invited(&client))
				{
					client.appendToWriteBuffer(":IRCServer 473 " + channel + " :Cannot join channel (+i)\r\n");
					continue;
				}
				if (!chan->getKey().empty() && key != chan->getKey())
				{
					client.appendToWriteBuffer(":IRCServer 475 " + channel + " :Cannot join channel (+k)\r\n");
					continue;
				}
				if (!chan->has_client(&client))
				{
					if (chan->get_Userlimit() > 0 && static_cast<int>(chan->getClients().size()) >= chan->get_Userlimit())
					{
						client.appendToWriteBuffer(":IRCServer 471 " + channel + " :Cannot join channel (+l)\r\n");
						continue;
					}
					bool wasEmpty = chan->getClients().empty();
					chan->add_client(&client);
					if (wasEmpty)
						chan->add_operator(&client);
					if (chan->has_invited(&client))
						chan->remove_invited(&client);

					std::string joinMsg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost JOIN " + channel + "\r\n";
					std::vector<Client *> &members = chan->getClients();
					for (size_t i = 0; i < members.size(); i++)
						members[i]->appendToWriteBuffer(joinMsg);
				}
			}
		}
	}
	else if (cmd == "PART")
	{
		if (!client.isRegistered())
		{
			client.appendToWriteBuffer(":IRCServer 451 * :You have not registered\r\n");
			return;
		}
		std::string channel;
		std::string reason;
		if (!input.PART(param, channel, reason))
		{
			client.appendToWriteBuffer(":IRCServer 461 * PART :Not enough parameters\r\n");
			return;
		}
		if (_server)
		{
			Channel *chan = _server->getChannel(channel);
			if (!chan)
			{
				client.appendToWriteBuffer(":IRCServer 403 " + channel + " :No such channel\r\n");
				return;
			}
			if (!chan->has_client(&client))
			{
				client.appendToWriteBuffer(":IRCServer 442 " + channel + " :You're not on that channel\r\n");
				return;
			}
			std::string part_msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost PART " + channel;
			if (!reason.empty())
				part_msg += " :" + reason;
			part_msg += "\r\n";
			std::vector<Client *> &members = chan->getClients();
			for (size_t i = 0; i < members.size(); i++)
				members[i]->appendToWriteBuffer(part_msg);
			chan->remove_client(&client);
			if (chan->has_operator(&client))
				chan->remove_operator(&client);
			_server->removeEmptyChannel(channel);
		}
	}
	else if (cmd == "PRIVMSG")
	{
		if (!client.isRegistered())
		{
			client.appendToWriteBuffer(":IRCServer 451 * :You have not registered\r\n");
			return;
		}
		std::string target;
		std::string message;
		if (!input.PRIVMSG(param, target, message))
		{
			client.appendToWriteBuffer(":IRCServer 461 * PRIVMSG :Not enough parameters\r\n");
			return;
		}
		if (!_server)
			return;

		bool isChannel = (!target.empty() && (target[0] == '#' || target[0] == '&'));
		if (isChannel)
		{
			Channel *chan = _server->getChannel(target);
			if (!chan)
			{
				client.appendToWriteBuffer(":IRCServer 403 " + target + " :No such channel\r\n");
				return;
			}
			if (!chan->has_client(&client))
			{
				client.appendToWriteBuffer(":IRCServer 442 " + target + " :You're not on that channel\r\n");
				return;
			}

			std::vector<Client *> &members = chan->getClients();

			for (size_t i = 0; i < members.size(); i++)
			{
				if (members[i] != &client)
				{
					std::string msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost PRIVMSG " + target + " :" + message + "\r\n";
					members[i]->appendToWriteBuffer(msg);
				}
			}

			if (_bot.isCommand(message))
			{
				if (message.size() > 1)
					_bot.handleMessage(client, *chan, message);
			}
		}
		else
		{
			std::map<int, Client> &clients = _server->getClients();
			Client *target_client = NULL;
			for (std::map<int, Client>::iterator iter = clients.begin(); iter != clients.end(); iter++)
			{
				if (iter->second.getNickname() == target)
				{
					target_client = &iter->second;
					break;
				}
			}
			if (!target_client)
			{
				client.appendToWriteBuffer(":IRCServer 401 " + target + " :No such nick/channel\r\n");
				return;
			}
			std::string msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost PRIVMSG " + target + " :" + message + "\r\n";
			target_client->appendToWriteBuffer(msg);

			std::string filename;
			std::string ip;
			std::string port;
			std::string size;
			if (_fileTransfer.parseSend(message, filename, ip, port, size))
			{
				std::cout << "file transfer offer: " << client.getNickname() << " -> " << target << " " << filename << " (" << size << " bytes)\n";
				target_client->appendToWriteBuffer(_fileTransfer.buildNotice(client, target, filename, size));
			}
		}
	}
	else if (cmd == "KICK")
	{
		if (!client.isRegistered())
		{
			client.appendToWriteBuffer(":IRCServer 451 * :You have not registered\r\n");
			return;
		}
		std::string channel;
		std::string user;
		std::string reason;
		if (!input.KICK(param, channel, user, reason))
		{
			client.appendToWriteBuffer(":IRCServer 461 * KICK :Not enough parameters\r\n");
			return;
		}
		if (_server)
		{
			Channel *chan = _server->getChannel(channel);
			if (!chan)
			{
				client.appendToWriteBuffer(":IRCServer 403 " + channel + " :No such channel\r\n");
				return;
			}
			if (!chan->has_client(&client))
			{
				client.appendToWriteBuffer(":IRCServer 442 " + channel + " :You're not on that channel\r\n");
				return;
			}
			if (!chan->has_operator(&client))
			{
				client.appendToWriteBuffer(":IRCServer 482 " + channel + " :You're not channel operator\r\n");
				return;
			}
			std::vector<Client *> &members = chan->getClients();
			Client *chan_client = NULL;
			for (size_t i = 0; i < members.size(); i++)
			{
				if (members[i]->getNickname() == user)
				{
					chan_client = members[i];
					break;
				}
			}
			if (!chan_client)
			{
				client.appendToWriteBuffer(":IRCServer 441 " + user + " " + channel + " :They aren't on that channel\r\n");
				return;
			}
			for (size_t i = 0; i < members.size(); i++)
			{
				std::string kick_msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost KICK " + channel + " " + user;
				if (!reason.empty())
					kick_msg += " :" + reason;
				kick_msg += "\r\n";
				members[i]->appendToWriteBuffer(kick_msg);
			}
			chan->remove_client(chan_client);
			if (chan->has_operator(chan_client))
				chan->remove_operator(chan_client);
			_server->removeEmptyChannel(channel);
		}
	}
	else if (cmd == "INVITE")
	{
		if (!client.isRegistered())
		{
			client.appendToWriteBuffer(":IRCServer 451 * :You have not registered\r\n");
			return;
		}
		std::string channel;
		std::string user;
		if (!input.INVITE(param, user, channel))
		{
			client.appendToWriteBuffer(":IRCServer 461 * INVITE :Not enough parameters\r\n");
			return;
		}
		if (_server)
		{
			Channel *chann = _server->getChannel(channel);
			if (!chann)
			{
				client.appendToWriteBuffer(":IRCServer 403 " + channel + " :No such channel\r\n");
				return;
			}
			if (!chann->has_client(&client))
			{
				client.appendToWriteBuffer(":IRCServer 442 " + channel + " :You're not on that channel\r\n");
				return;
			}
			if (!chann->has_operator(&client))
			{
				client.appendToWriteBuffer(":IRCServer 482 " + channel + " :You're not channel operator\r\n");
				return;
			}
			Client *invite_client = NULL;
			std::map<int, Client> &clients = _server->getClients();
			for (std::map<int, Client>::iterator iter = clients.begin(); iter != clients.end(); iter++)
			{
				if (iter->second.getNickname() == user)
				{
					invite_client = &iter->second;
					break;
				}
			}
			if (!invite_client)
			{
				client.appendToWriteBuffer(":IRCServer 401 " + user + " :No such nick\r\n");
				return;
			}
			if (chann->has_client(invite_client))
			{
				client.appendToWriteBuffer(":IRCServer 443 " + user + " " + channel + " :is already on channel\r\n");
				return;
			}
			chann->add_invited(invite_client);
			std::string invite_msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost INVITE " + user + " " + channel + "\r\n";
			invite_client->appendToWriteBuffer(invite_msg);
			client.appendToWriteBuffer(":IRCServer 341 " + client.getNickname() + " " + user + " " + channel + "\r\n");
		}
	}
	else if (cmd == "TOPIC")
	{
		if (!client.isRegistered())
		{
			client.appendToWriteBuffer(":IRCServer 451 * :You have not registered\r\n");
			return;
		}
		std::string channel;
		std::string topic;
		bool hasTopic;
		if (!input.TOPIC(param, channel, topic, hasTopic))
		{
			client.appendToWriteBuffer(":IRCServer 461 * TOPIC :Not enough parameters\r\n");
			return;
		}
		if (_server)
		{
			Channel *chann = _server->getChannel(channel);
			if (!chann)
			{
				client.appendToWriteBuffer(":IRCServer 403 " + channel + " :No such channel\r\n");
				return;
			}
			if (!chann->has_client(&client))
			{
				client.appendToWriteBuffer(":IRCServer 442 " + channel + " :You're not on that channel\r\n");
				return;
			}
			if (!hasTopic)
			{
				if (chann->getTopic().empty())
				{
					client.appendToWriteBuffer(":IRCServer 331 " + client.getNickname() + " " + channel + " :No topic is set\r\n");
					return;
				}
				else
					client.appendToWriteBuffer(":IRCServer 332 " + client.getNickname() + " " + channel + " :" + chann->getTopic() + "\r\n");
				return;
			}
			if (chann->getTopicOnly() && !chann->has_operator(&client))
			{
				client.appendToWriteBuffer(":IRCServer 482 " + channel + " :You're not channel operator\r\n");
				return;
			}
			chann->setTopic(topic);
			std::vector<Client *> &members = chann->getClients();
			for (size_t i = 0; i < members.size(); i++)
			{
				std::string topic_msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost TOPIC " + channel + " :" + topic + "\r\n";
				members[i]->appendToWriteBuffer(topic_msg);
			}
		}
	}
	else if (cmd == "MODE")
	{
		if (!client.isRegistered())
		{
			client.appendToWriteBuffer(":IRCServer 451 * :You have not registered\r\n");
			return;
		}
		std::string channel;
		std::string mode;
		std::string mode_param;
		if (!input.MODE(param, channel, mode, mode_param))
		{
			client.appendToWriteBuffer(":IRCServer 461 * MODE :Not enough parameters\r\n");
			return;
		}
		if (_server)
		{
			Channel *chan = _server->getChannel(channel);
			if (!chan)
			{
				client.appendToWriteBuffer(":IRCServer 403 " + channel + " :No such channel\r\n");
				return;
			}
			if (!chan->has_client(&client))
			{
				client.appendToWriteBuffer(":IRCServer 442 " + channel + " :You're not on that channel\r\n");
				return;
			}
			if (!chan->has_operator(&client))
			{
				client.appendToWriteBuffer(":IRCServer 482 " + channel + " :You're not channel operator\r\n");
				return;
			}
			bool compoundSimpleMode = mode.size() > 2 && (mode[0] == '+' || mode[0] == '-');
			if (compoundSimpleMode)
			{
				for (size_t i = 1; i < mode.size(); i++)
				{
					if (mode[i] == 'i')
						chan->setInviteOnly(mode[0] == '+');
					else if (mode[i] == 't')
						chan->setTopicOnly(mode[0] == '+');
				}
				std::string modeMsg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost MODE " + channel + " " + mode + "\r\n";
				std::vector<Client *> &members = chan->getClients();
				for (size_t i = 0; i < members.size(); i++)
					members[i]->appendToWriteBuffer(modeMsg);
			}
			else if (mode == "+i")
			{
				chan->setInviteOnly(true);
				std::vector<Client *> &members = chan->getClients();
				for (size_t i = 0; i < members.size(); i++)
				{
					std::string mode_msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost MODE " + channel + " +i\r\n";
					members[i]->appendToWriteBuffer(mode_msg);
				}
			}
			else if (mode == "-i")
			{
				chan->setInviteOnly(false);
				std::vector<Client *> &members = chan->getClients();
				for (size_t i = 0; i < members.size(); i++)
				{
					std::string mode_msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost MODE " + channel + " -i\r\n";
					members[i]->appendToWriteBuffer(mode_msg);
				}
			}
			else if (mode == "+t")
			{
				chan->setTopicOnly(true);
				std::vector<Client *> &members = chan->getClients();
				for (size_t i = 0; i < members.size(); i++)
				{
					std::string mode_msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost MODE " + channel + " +t\r\n";
					members[i]->appendToWriteBuffer(mode_msg);
				}
			}
			else if (mode == "-t")
			{
				chan->setTopicOnly(false);
				std::vector<Client *> &members = chan->getClients();
				for (size_t i = 0; i < members.size(); i++)
				{
					std::string mode_msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost MODE " + channel + " -t\r\n";
					members[i]->appendToWriteBuffer(mode_msg);
				}
			}
			else if (mode == "+k")
			{
				if (mode_param.empty())
				{
					client.appendToWriteBuffer(":IRCServer 461 MODE :Need parameter for +k\r\n");
					return;
				}
				chan->setKey(mode_param);
				std::string msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost MODE " + channel + " +k " + mode_param + "\r\n";
				std::vector<Client *> &members = chan->getClients();
				for (std::vector<Client *>::iterator it = members.begin(); it != members.end(); it++)
					(*it)->appendToWriteBuffer(msg);
			}
			else if (mode == "-k")
			{
				chan->setKey("");
				std::string msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost MODE " + channel + " -k\r\n";
				std::vector<Client *> &members = chan->getClients();
				for (std::vector<Client *>::iterator it = members.begin(); it != members.end(); it++)
					(*it)->appendToWriteBuffer(msg);
			}
			else if (mode == "+o")
			{
				if (mode_param.empty())
				{
					client.appendToWriteBuffer(":IRCServer 461 MODE :Need parameter for +o\r\n");
					return;
				}
				std::map<int, Client> &clients = _server->getClients();
				Client *target = NULL;
				for (std::map<int, Client>::iterator it = clients.begin(); it != clients.end(); it++)
				{
					if (it->second.getNickname() == mode_param)
					{
						target = &it->second;
						break;
					}
				}
				if (target == NULL)
				{
					client.appendToWriteBuffer(":IRCServer 401 " + mode_param + " :No such nick\r\n");
					return;
				}
				if (!chan->has_client(target))
				{
					client.appendToWriteBuffer(":IRCServer 441 " + mode_param + " " + channel + " :They aren't on that channel\r\n");
					return;
				}
				if (!chan->has_operator(target))
					chan->add_operator(target);
				std::string msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost MODE " + channel +
								  " +o " + mode_param + "\r\n";
				std::vector<Client *> &members = chan->getClients();
				for (std::vector<Client *>::iterator it = members.begin(); it != members.end(); it++)
					(*it)->appendToWriteBuffer(msg);
			}
			else if (mode == "-o")
			{
				if (mode_param.empty())
				{
					client.appendToWriteBuffer(":IRCServer 461 MODE :Need parameter for -o\r\n");
					return;
				}
				std::map<int, Client> &clients = _server->getClients();
				Client *target = NULL;
				for (std::map<int, Client>::iterator it = clients.begin(); it != clients.end(); it++)
				{
					if (it->second.getNickname() == mode_param)
					{
						target = &it->second;
						break;
					}
				}
				if (target == NULL)
				{
					client.appendToWriteBuffer(":IRCServer 401 " + mode_param + " :No such nick\r\n");
					return;
				}
				if (!chan->has_client(target))
				{
					client.appendToWriteBuffer(":IRCServer 441 " + mode_param + " " + channel + " :They aren't on that channel\r\n");
					return;
				}
				if (chan->has_operator(target))
					chan->remove_operator(target);
				std::string msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost MODE " + channel +
								  " -o " + mode_param + "\r\n";
				std::vector<Client *> &members = chan->getClients();
				for (std::vector<Client *>::iterator it = members.begin(); it != members.end(); it++)
					(*it)->appendToWriteBuffer(msg);
			}
			else if (mode == "+l")
			{
				if (mode_param.empty())
				{
					client.appendToWriteBuffer(":IRCServer 461 MODE :Need parameter for +l\r\n");
					return;
				}
				int limit;
				std::stringstream ss(mode_param);
				char valid_limit;
				if (!(ss >> limit) || (ss >> valid_limit) || limit <= 0)
				{
					client.appendToWriteBuffer(":IRCServer 461 MODE :Invalid user limit\r\n");
					return;
				}
				chan->set_Userlimit(limit);
				std::string msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost MODE " + channel +
								  " +l " + mode_param + "\r\n";
				std::vector<Client *> &members = chan->getClients();
				for (std::vector<Client *>::iterator it = members.begin(); it != members.end(); it++)
					(*it)->appendToWriteBuffer(msg);
			}
			else if (mode == "-l")
			{
				chan->set_Userlimit(0);
				std::string msg = ":" + client.getNickname() + "!" + client.getUsername() + "@localhost MODE " + channel + " -l\r\n";
				std::vector<Client *> &members = chan->getClients();
				for (std::vector<Client *>::iterator it = members.begin(); it != members.end(); it++)
					(*it)->appendToWriteBuffer(msg);
			}
			else
				client.appendToWriteBuffer(":IRCServer 472 " + mode + " :Unknown mode\r\n");
		}
	}
	else
		client.appendToWriteBuffer(":IRCServer 421 " + client.getNickname() + " " + cmd + " :Unknown command\r\n");
}
