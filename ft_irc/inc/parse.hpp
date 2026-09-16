#ifndef PARSE_HPP
#define PARSE_HPP

#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "client.hpp"

class parse
{
	private:
		std::string	commands;
		std::string	args;

	public:
		bool	PASS(std::string &param, const std::string &password);
		bool	NICK(std::string &param);
		bool	PART(const std::string &param, std::string &channel, std::string &reason);
		bool	USER(const std::string &param, Client &client);
		bool	PRIVMSG(const std::string &param, std::string &channel, std::string &message);
		bool	KICK(const std::string &param, std::string &channel, std::string &user, std::string &reason);
		bool	INVITE(const std::string &param, std::string &user, std::string &channel);
		bool	TOPIC(const std::string &param, std::string &channel, std::string &topic, bool &hasTopic);
		bool	MODE(const std::string &param, std::string &channel, std::string &mode, std::string &mode_param);
		bool	JOIN_MULTI(const std::string &param, std::vector<std::string> &channels, std::vector<std::string> &keys);
};

#endif
