#ifndef BOT_HPP
#define BOT_HPP

#include <string>

class Client;
class Channel;

class Bot
{
	private:
		std::string		_nickname;
		std::string		_username;
		Bot(const Bot &other);
		Bot				&operator=(const Bot &other);
		std::string		buildPrefix() const;
		void			broadcast(Channel &channel, const std::string &text) const;
		std::string		executeCommand(Channel &channel, Client &sender, const std::string &command, const std::string &arg) const;
	public:
		Bot(const std::string	&nickname);

		bool					isCommand(const std::string &message) const;
		void					handleMessage(Client &sender, Channel &channel, const std::string &message);
		~Bot();
};

#endif
