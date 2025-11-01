/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:06:04 by youbella          #+#    #+#             */
/*   Updated: 2025/10/27 11:44:23 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>

int	main(int argc, char **argv)
{
	std::string		line;
	std::string		s1;
	std::string		s2;
	size_t			pos;

	if (argc != 4)
	{
		std::cout << "Enter:\n<filename> <s1> <s2>\n";
		return (1);
	}
	s1 = argv[2];
	s2 = argv[3];
	std::ifstream	file(argv[1]);
	if (s1.empty())
	{
		std::cout << "<s1> is empty\n";
		return (1);
	}
	if (!file.is_open())
	{
		std::cout << "Fil e not open.\n";
		return (1);
	}
	std::ofstream	newFile(((std::string)argv[1]).append(".replace"));
	if (!newFile.is_open())
	{
		std::cout << "NewFile not open.\n";
		file.close();
		return (1);
	}
	std::ostringstream	buffer;
	buffer << file.rdbuf();
	std::string content = buffer.str();
	pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content = content.substr(0, pos) + s2 + content.substr(pos + s1.length());
        pos += s2.length();
    }
	newFile << content;
	file.close();
	newFile.close();
	return (0);
}
