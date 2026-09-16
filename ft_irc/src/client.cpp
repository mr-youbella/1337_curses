#include "../inc/client.hpp"
#include <iostream>

Client::Client() : _fd(-1), _registered(false), _pass(false), _hasNickname(false), _hasUsername(false) {}

Client::Client(int fd) : _fd(fd), _registered(false), _pass(false), _hasNickname(false), _hasUsername(false) {}

Client::~Client() {}

int Client::getFd() const
{
	return (_fd);
}

const std::string &Client::getNickname() const
{
	return (_nickname);
}

const std::string &Client::getUsername() const
{
	return (_username);
}

bool Client::isRegistered() const
{
	return (_registered);
}

void Client::setNickname(const std::string &nickname)
{
	_nickname = nickname;
}

void Client::setUsername(const std::string &username)
{
	_username = username;
}

void Client::setRegistered(bool value)
{
	_registered = value;
}

void Client::setPassed(bool value)
{
	_pass = value;
}

bool Client::get_Passed()
{
	return _pass;
}

void Client::set_hasNickname(bool value)
{
	_hasNickname = value;
}

bool Client::get_hasNickname()
{
	return _hasNickname;
}

void Client::set_hasUsername(bool value)
{
	_hasUsername = value;
}

bool Client::get_hasUsername()
{
	return _hasUsername;
}

bool Client::appendToReadBuffer(const char *data, int len)
{
	if (len <= 0)
		return true;

	size_t newSize = _read_buffer.size() + static_cast<size_t>(len);
	if (newSize > MAX_BUFFER_SIZE)
		return false;

	_read_buffer.append(data, len);
	return true;
}

bool Client::hasCompleteLine() const
{
	return (_read_buffer.find("\n") != std::string::npos);
}

std::string Client::extractLine()
{
	const size_t pos = _read_buffer.find("\n");
	if (pos == std::string::npos)
		return ("");

	std::string line = _read_buffer.substr(0, pos);
	_read_buffer.erase(0, pos + 1);

	if (!line.empty() && line[line.size() - 1] == '\r')
		line.erase(line.size() - 1);

	return (line);
}

void Client::appendToWriteBuffer(const std::string &data)
{
	_write_buffer.append(data);
}

const std::string &Client::getWriteBuffer() const
{
	return (_write_buffer);
}

void Client::eraseWriteBuffer(size_t n)
{
	if (n >= _write_buffer.size())
		_write_buffer.clear();
	else
		_write_buffer.erase(0, n);
}

bool Client::hasDataToWrite() const
{
	return (!_write_buffer.empty());
}
