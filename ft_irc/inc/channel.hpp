#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Client;

class Channel
{
	private:
		std::string				_name;
		std::vector<Client *>	_client;
		std::vector<Client *>	_operator;
		std::string				_topic;
		std::vector<Client *>	_invited;
		bool					_inviteOnly;
		bool					_topicOnly;
		std::string				_key;
		int						_limitUser;

	public:
		Channel(const std::string &name);

		const std::string		&getName() const;
		void					add_client(Client *client);
		bool					has_client(Client *client) const;
		void					remove_client(Client *client);
		bool					isEmpty() const;
		void					add_operator(Client *client);
		bool					has_operator(Client *client) const;
		void					remove_operator(Client *client);
		std::vector<Client *>	&getClients();
		const std::string		&getTopic() const;
		void					setTopic(std::string &topic);
		void					add_invited(Client *client);
		bool					has_invited(Client *client) const;
		void					remove_invited(Client *client);
		bool					getInviteOnly() const;
		void					setInviteOnly(bool invite);
		bool					getTopicOnly() const;
		void					setTopicOnly(bool topic);
		std::string				getKey() const;
		void					setKey(const std::string &key);
		int						get_Userlimit() const;
		void					set_Userlimit(int limit);
};

#endif
