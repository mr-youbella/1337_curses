#include "../inc/server.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << "usage: ./ircserv <port> <password>\n";
		return (1);
	}

	const char		*begin = argv[1];
	char			*end = NULL;
	long			port = std::strtol(begin, &end, 10);
	if (end == begin || *end != '\0' || port <= 0 || port > 65535)
	{
		std::cerr << "invalid port\n";
		return (1);
	}

	const std::string password = argv[2];

	Server server(static_cast<int>(port), password);
	server.run();

	return (0);
}
