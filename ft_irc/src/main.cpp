#include "../inc/server.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << "usage: ./ircserv <port> <password>\n";
		return (1);
	}

	const int port = std::atoi(argv[1]);
	if (port <= 0 || port > 65535)
	{
		std::cerr << "invalid port\n";
		return (1);
	}

	const std::string password = argv[2];

	Server server(port, password);
	server.run();

	return (0);
}
