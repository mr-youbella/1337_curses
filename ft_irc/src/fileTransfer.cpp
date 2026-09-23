#include "../inc/fileTransfer.hpp"

static const char CTCP_DELIM = '\x01';

FileTransfer::FileTransfer() {}

FileTransfer::~FileTransfer() {}

bool FileTransfer::isDccSend(const std::string &message) const
{
	if (message.size() < 9)
		return (false);
	if (message[0] != CTCP_DELIM)
		return (false);
	return (message.compare(1, 8, "DCC SEND") == 0);
}

bool FileTransfer::parseSend(const std::string &message, std::string &filename, std::string &ip, std::string &port, std::string &size) const
{
	if (!isDccSend(message))
		return (false);

	std::string payload = message.substr(1);
	size_t end = payload.find(CTCP_DELIM);
	if (end != std::string::npos)
		payload = payload.substr(0, end);

	std::istringstream iss(payload);
	std::string dccWord;
	std::string sendWord;

	if (!(iss >> dccWord >> sendWord) || dccWord != "DCC" || sendWord != "SEND")
		return (false);
	if (!(iss >> filename >> ip >> port >> size))
		return (false);
	return (true);
}

std::string FileTransfer::buildNotice(Client &sender, const std::string &targetNick, const std::string &filename, const std::string &size) const
{
	return (":IRCServer NOTICE " + targetNick + " :" + sender.getNickname() + " wants to send you a file: " + filename + " (" + size + " bytes). " + "Your client should offer to accept it.\r\n");
}
