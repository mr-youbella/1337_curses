#include "../inc/channel.hpp"
#include <algorithm>

Channel::Channel(const std::string &name) : _name(name), _inviteOnly(false), _topicOnly(true), _key(""), _limitUser(0) {}

const std::string &Channel::getName() const
{
	return (_name);
}

void Channel::add_client(Client *client)
{
	if (!has_client(client))
		_client.push_back(client);
}

bool Channel::has_client(Client *client) const
{
	std::vector<Client *>::const_iterator iter = _client.begin();
	while (iter != _client.end())
	{
		if (*iter == client)
			return true;
		iter++;
	}
	return false;
}

void Channel::remove_client(Client *client)
{
	std::vector<Client *>::iterator iter = _client.begin();
	while (iter != _client.end())
	{
		if (*iter == client)
		{
			_client.erase(iter);
			return;
		}
		iter++;
	}
}

bool Channel::isEmpty() const
{
	return _client.empty();
}

bool Channel::has_operator(Client *client) const
{
	std::vector<Client *>::const_iterator iter = _operator.begin();
	while (iter != _operator.end())
	{
		if (*iter == client)
			return true;
		iter++;
	}
	return false;
}

void Channel::add_operator(Client *client)
{
	if (!has_operator(client))
		_operator.push_back(client);
}

void Channel::remove_operator(Client *client)
{
	std::vector<Client *>::iterator iter = _operator.begin();
	while (iter != _operator.end())
	{
		if (*iter == client)
		{
			_operator.erase(iter);
			return;
		}
		iter++;
	}
}

std::vector<Client *> &Channel::getClients()
{
	return _client;
}

const std::string &Channel::getTopic() const
{
	return _topic;
}

void Channel::setTopic(std::string &topic)
{
	while (!topic.empty() && (topic[0] == ' ' || topic[0] == '\r' || topic[0] == '\n' || topic[0] == '\t'))
		topic.erase(0, 1);

	while (!topic.empty() && (topic[topic.size() - 1] == ' ' || topic[topic.size() - 1] == '\r' || topic[topic.size() - 1] == '\n' || topic[topic.size() - 1] == '\t'))
		topic.erase(topic.size() - 1);

	_topic = topic;
}

void Channel::add_invited(Client *client)
{
	if (!has_invited(client))
		_invited.push_back(client);
}

bool Channel::has_invited(Client *client) const
{
	std::vector<Client *>::const_iterator iter = _invited.begin();
	while (iter != _invited.end())
	{
		if (*iter == client)
			return true;
		iter++;
	}
	return false;
}

void Channel::remove_invited(Client *client)
{
	std::vector<Client *>::iterator iter = _invited.begin();
	while (iter != _invited.end())
	{
		if (*iter == client)
		{
			_invited.erase(iter);
			return;
		}
		iter++;
	}
}

bool Channel::getInviteOnly() const
{
	return (_inviteOnly);
}

void Channel::setInviteOnly(bool invite)
{
	_inviteOnly = invite;
}

bool Channel::getTopicOnly() const
{
	return _topicOnly;
}

void Channel::setTopicOnly(bool topic)
{
	_topicOnly = topic;
}

std::string Channel::getKey() const
{
	return _key;
}

void Channel::setKey(const std::string &key)
{
	_key = key;
}

int Channel::get_Userlimit() const
{
	return _limitUser;
}

void Channel::set_Userlimit(int limit)
{
	_limitUser = limit;
}
