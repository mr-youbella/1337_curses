#ifndef FILE_TRANSFER_HPP
#define FILE_TRANSFER_HPP

#include <string>
#include <sstream>
#include "client.hpp"

class Client;

class FileTransfer
{
	private:
		FileTransfer(const FileTransfer &other);
		FileTransfer	&operator=(const FileTransfer &other);
		
	public:
		FileTransfer();
		~FileTransfer();

		bool		isDccSend(const std::string &message) const;
		bool		parseSend(const std::string &message, std::string &filename, std::string &ip, std::string &port, std::string &size) const;
		std::string	buildNotice(Client &sender, const std::string &targetNick, const std::string &filename, const std::string &size) const;
};

#endif
