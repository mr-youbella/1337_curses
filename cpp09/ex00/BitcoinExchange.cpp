/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:24:47 by youbella          #+#    #+#             */
/*   Updated: 2026/03/12 20:34:21 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_database = other._database;
	return (*this);
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file.\n";
		return ;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue ;
		std::string date = line.substr(0, comma);
		double rate = std::strtod(line.substr(comma + 1).c_str(), NULL);
		_database[date] = rate;
	}
	file.close();
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(date[i]))
			return (false);
	}
	int	year  = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day   = std::atoi(date.substr(8, 2).c_str());
	int	daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2)
	{
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    	if (day > (isLeap ? 29 : 28))
			return false;
    } 
	else if (day > daysInMonth[month - 1])
        return false;
	if (year < 2009)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	return (true);
}

std::string ft_trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return ("");
    size_t last = str.find_last_not_of(" \t");
    return (str.substr(first, (last - first + 1)));
}

void BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream	file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file.\n";
		return ;
	}
	std::string	line;
	while (std::getline(file, line))
	{
		if (line.empty() || line.find_first_not_of(" \t\n") == std::string::npos)
			continue;
		if (!(ft_trim(line).length() == 12 && ft_trim(line).find("date | value") != std::string::npos))
		{
			std::cerr << "Error: invalid header format.\n";
			return ;
		}
		break ;
	}
	while (std::getline(file, line))
	{
		if (line.empty() || line.find_first_not_of(" \t\n\r") == std::string::npos)
			continue;
		size_t sep = ft_trim(line).find(" | ");
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << ft_trim(line) << '\n';
			continue ;
		}
		std::string date  = ft_trim(line).substr(0, sep);
		std::string value = ft_trim(line).substr(sep + 3);
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << ft_trim(line) << '\n';
			continue ;
		}
		char	*end;
		double	amount = std::strtod(value.c_str(), &end);
		if (*end != '\0' || value.empty())
		{
			std::cerr << "Error: bad input => " << ft_trim(line) << '\n';
			continue ;
		}
		if (amount < 0)
		{
			std::cerr << "Error: not a positive number.\n";
			continue ;
		}
		if (amount > 1000)
		{
			std::cerr << "Error: too large a number.\n";
			continue ;
		}
		std::map<std::string, double>::iterator it = _database.lower_bound(date);
		if (it == _database.end() || it->first != date)
		{
			if (it == _database.begin())
			{
				std::cerr << "Error: bad input => " << date << '\n';
				continue ;
			}
			--it;
		}
		std::cout << date << " => " << amount << " = " << amount * it->second << '\n';
	}
	file.close();
}

BitcoinExchange::~BitcoinExchange() {}
