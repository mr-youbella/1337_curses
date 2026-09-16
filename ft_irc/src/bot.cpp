#include "../inc/bot.hpp"
#include "../inc/client.hpp"
#include "../inc/channel.hpp"
#include <cctype>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <sstream>

Bot::Bot(const std::string &nickname) : _nickname(nickname), _username("bot")
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
}

Bot::~Bot() {}

bool	Bot::isCommand(const std::string &message) const
{
	return (message.size() > 1 && message[0] == '!');
}

std::string	Bot::buildPrefix() const
{
	return (":" + _nickname + "!" + _username + "@localhost");
}

void	Bot::broadcast(Channel &channel, const std::string &text) const
{
	std::vector<Client *> &members = channel.getClients();
	for (size_t i = 0; i < members.size(); i++)
		members[i]->appendToWriteBuffer(text);
}

std::string	Bot::executeCommand(Channel &channel, Client &sender, const std::string &command, const std::string &arg) const
{
	if (command == "help")
		return ("Available commands: !help, !time, !dice [max], !users, !topic, !ping");

	if (command == "time")
	{
		std::time_t	now = std::time(NULL);
		std::string	str(std::ctime(&now));
		if (!str.empty() && str[str.size() - 1] == '\n')
			str.erase(str.size() - 1);
		return ("Server time is " + str);
	}

	if (command == "dice")
	{
		int	max = 6;
		if (!arg.empty())
		{
			const char		*begin = arg.c_str();
			char			*end = NULL;
			long			value = std::strtol(begin, &end, 10);
			if (end == begin || *end != '\0' || value <= 0 || value > INT_MAX)
				return ("Usage: !dice [positive number], example: !dice 20");
			max = static_cast<int>(value);
		}
		int	result = (std::rand() % max) + 1;
		std::stringstream	out;
		out << sender.getNickname() << " rolled " << result << " (out of " << max << ")";
		return (out.str());
	}

	if (command == "users")
	{
		std::vector<Client *> &members = channel.getClients();
		std::string	list;
		for (size_t i = 0; i < members.size(); i++)
		{
			if (i > 0)
				list += ", ";
			list += members[i]->getNickname();
		}
		if (list.empty())
			return ("No one is here.");
		return ("Users here: " + list);
	}

	if (command == "topic")
	{
		if (channel.getTopic().empty())
			return ("No topic is set.");
		return ("Topic: " + channel.getTopic());
	}

	if (command == "ping")
		return ("Pong!");

	return ("Unknown command '" + command + "'. Type !help for the list of commands.");
}

void	Bot::handleMessage(Client &sender, Channel &channel, const std::string &message)
{
	if (message.size() <= 1)
		return;
		
	std::string	body = message.substr(1);
	size_t		pos = body.find(' ');
	std::string	command;
	std::string	arg;

	if (pos == std::string::npos)
		command = body;
	else
	{
		command = body.substr(0, pos);
		arg = body.substr(pos + 1);
	}

	for (size_t i = 0; i < command.size(); i++)
		command[i] = static_cast<char>(std::tolower(command[i]));

	std::string	response = executeCommand(channel, sender, command, arg);
	std::string	line = buildPrefix() + " PRIVMSG " + channel.getName() + " :" + response + "\r\n";
	broadcast(channel, line);
}
