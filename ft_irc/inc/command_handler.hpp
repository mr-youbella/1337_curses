#ifndef COMMANDHANDLER_HPP
#define COMMANDHANDLER_HPP

#include <string>
#include "client.hpp"
#include "parse.hpp"
#include "bot.hpp"
#include "fileTransfer.hpp"

class Server;

class CommandHandler
{
	private:
		std::string		_password;
		Server			*_server;
		bool			_should_disconnect;
		Bot				_bot;
		FileTransfer	_fileTransfer;
		
		CommandHandler();
		CommandHandler(const CommandHandler &other);
		CommandHandler	&operator=(const CommandHandler &other);
		void			handlePing(Client &client, const std::string &param);
		void			handleQuit(Client &client);
		void			handlePass(Client &client, const std::string &param);
		void			handleNick(Client &client, const std::string &param);
		void			handleUser(Client &client, const std::string &param);
		
	public:
		CommandHandler(const std::string &password);
		~CommandHandler();

		void			setServer(Server *server);
		void			execute(Client &client, const std::string &line);
		bool			shouldDisconnect() const;
};

#endif
