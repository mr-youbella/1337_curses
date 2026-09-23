#include "../inc/parse.hpp"

bool parse::PASS(std::string &param, const std::string &password)
{
	if (param.empty())
		return (false);
	if (param != password)
		return (false);
	return true;
}

bool parse::NICK(std::string &param)
{
	if (param.empty())
		return false;
	return true;
}

bool parse::JOIN_MULTI(const std::string &param, std::vector<std::string> &channels, std::vector<std::string> &keys)
{
	channels.clear();
	keys.clear();
	if (param.empty())
		return false;

	size_t space = param.find(' ');
	std::string channelList = param.substr(0, space);
	std::string keyList;
	if (space != std::string::npos)
	{
		keyList = param.substr(space + 1);
		if (keyList.empty() || keyList.find(' ') != std::string::npos)
			return false;
	}

	size_t start = 0;
	while (start <= channelList.size())
	{
		size_t comma = channelList.find(',', start);
		std::string channel = channelList.substr(start, comma - start);
		if (channel.empty() || channel.size() > 50 || (channel[0] != '#' && channel[0] != '&'))
			return false;
		for (size_t i = 0; i < channel.size(); i++)
		{
			if (channel[i] == ' ' || channel[i] == '\r' || channel[i] == '\n')
				return false;
		}
		channels.push_back(channel);
		if (comma == std::string::npos)
			break;
		start = comma + 1;
	}

	if (!keyList.empty())
	{
		start = 0;
		while (start <= keyList.size())
		{
			size_t comma = keyList.find(',', start);
			std::string key = keyList.substr(start, comma - start);
			if (key.empty())
				return false;
			keys.push_back(key);
			if (comma == std::string::npos)
				break;
			start = comma + 1;
		}
	}
	return true;
}

bool parse::PART(const std::string &param, std::string &channel, std::string &reason)
{
	reason = "";
	if (param.empty())
		return false;
	std::string::const_iterator iter;
	iter = std::find(param.begin(), param.end(), ' ');
	std::string chan(param.begin(), iter);
	if (chan.empty())
		return false;
	channel = chan;
	if (iter != param.end())
	{
		std::string rest(iter + 1, param.end());
		if (!rest.empty() && rest[0] == ':')
		{
			std::string msg(rest.begin() + 1, rest.end());
			if (msg.empty())
				return false;
			reason = msg;
		}
		else
			return false;
	}
	return true;
}

bool parse::USER(const std::string &param, Client &client)
{
	std::string::const_iterator iter;
	iter = std::find(param.begin(), param.end(), ' ');
	if (iter == param.end())
		return false;
	std::string username(param.begin(), iter);
	if (username.empty())
		return false;
	std::string rest(iter + 1, param.end());
	std::string::iterator iter_mode;
	iter_mode = std::find(rest.begin(), rest.end(), ' ');
	if (iter_mode == rest.end())
		return false;
	std::string user_mode(rest.begin(), iter_mode);
	std::string rest2(iter_mode + 1, rest.end());
	iter_mode = std::find(rest2.begin(), rest2.end(), ' ');
	if (iter_mode == rest2.end())
		return false;
	std::string unused(rest2.begin(), iter_mode);
	std::string rest3(iter_mode + 1, rest2.end());
	if (rest3.empty() || rest3[0] != ':')
		return false;
	std::string real_name(rest3.begin() + 1, rest3.end());
	if (real_name.empty())
		return false;
	client.setUsername(username);
	return true;
}

bool parse::PRIVMSG(const std::string &param, std::string &channel, std::string &message)
{
	std::string::const_iterator iter;
	iter = std::find(param.begin(), param.end(), ' ');
	if (iter == param.end())
		return false;
	std::string token(param.begin(), iter);
	if (token.empty())
		return false;
	channel = token;
	std::string rest(iter + 1, param.end());
	if (rest.empty() || rest[0] != ':')
		return false;
	std::string msg(rest.begin() + 1, rest.end());
	if (msg.empty())
		return false;
	message = msg;
	return true;
}

bool parse::KICK(const std::string &param, std::string &channel, std::string &user, std::string &reason)
{
	reason = "";
	std::string::const_iterator iter;
	iter = std::find(param.begin(), param.end(), ' ');
	if (iter == param.end())
		return false;
	std::string token(param.begin(), iter);
	if (token.empty())
		return false;
	channel = token;
	std::string rest(iter + 1, param.end());
	std::string::iterator it;
	it = std::find(rest.begin(), rest.end(), ' ');
	std::string name(rest.begin(), it);
	if (name.empty())
		return false;
	user = name;
	if (it != rest.end())
	{
		std::string rest2(it + 1, rest.end());
		if (!rest2.empty() && rest2[0] == ':')
		{
			std::string explanation(rest2.begin() + 1, rest2.end());
			if (explanation.empty())
				return false;
			reason = explanation;
		}
		else
			return false;
	}

	return true;
}

bool parse::INVITE(const std::string &param, std::string &user, std::string &channel)
{
	std::string::const_iterator iter;
	iter = std::find(param.begin(), param.end(), ' ');
	if (iter == param.end())
		return false;
	std::string nickname(param.begin(), iter);
	if (nickname.empty())
		return false;
	user = nickname;
	std::string rest(iter + 1, param.end());
	if (rest.empty())
		return false;
	for (std::string::iterator it = rest.begin(); it != rest.end(); it++)
	{
		if (*it == ' ')
			return false;
	}
	channel = rest;
	return true;
}

bool parse::TOPIC(const std::string &param, std::string &channel, std::string &topic, bool &hasTopic)
{
	hasTopic = false;
	std::string::const_iterator iter;
	iter = std::find(param.begin(), param.end(), ' ');
	if (iter == param.end())
	{
		channel = param;
		if (channel.empty())
			return false;
		topic = "";
		return true;
	}
	std::string chain(param.begin(), iter);
	if (chain.empty())
		return false;
	channel = chain;
	std::string rest(iter + 1, param.end());
	if (rest.empty())
		topic = "";
	else if (!rest.empty() && rest[0] == ':')
	{
		std::string msg(rest.begin() + 1, rest.end());
		topic = msg;
		hasTopic = true;
	}
	else
		return false;
	return true;
}

bool parse::MODE(const std::string &param, std::string &channel, std::string &mode, std::string &mode_param)
{
	std::string::const_iterator iter = std::find(param.begin(), param.end(), ' ');
	if (iter == param.end())
		return false;
	std::string chann(param.begin(), iter);
	if (chann.empty())
		return false;
	channel = chann;
	std::string rest(iter + 1, param.end());
	if (rest.empty())
		return false;
	std::string::iterator it = std::find(rest.begin(), rest.end(), ' ');
	if (it == rest.end())
	{
		mode = rest;
		if (mode.empty())
			return false;
		if (mode == "+i" || mode == "-i" || mode == "+t" || mode == "-t" || mode == "-k" || mode == "-l")
		{
			mode_param = "";
			return true;
		}
		if (mode.size() > 2 && (mode[0] == '+' || mode[0] == '-'))
		{
			for (size_t i = 1; i < mode.size(); i++)
				if (mode[i] != 'i' && mode[i] != 't')
					return false;
			mode_param = "";
			return true;
		}
		return false;
	}
	std::string current_mode(rest.begin(), it);
	if (current_mode.empty())
		return false;
	mode = current_mode;
	std::string curr_mode_param(it + 1, rest.end());
	if (curr_mode_param.empty())
		return false;
	mode_param = curr_mode_param;
	return true;
}
