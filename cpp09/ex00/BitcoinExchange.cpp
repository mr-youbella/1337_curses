/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 01:53:59 by youbella          #+#    #+#             */
/*   Updated: 2026/03/11 00:54:33 by youbella         ###   ########.fr       */
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
	int year  = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());
	if (year < 2009)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	return (true);
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
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t sep = line.find(" | ");
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << '\n';
			continue ;
		}
		std::string date  = line.substr(0, sep);
		std::string value = line.substr(sep + 3);
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << '\n';
			continue ;
		}
		char	*end;
		double	amount = std::strtod(value.c_str(), &end);
		if (*end != '\0' || value.empty())
		{
			std::cerr << "Error: bad input => " << line << '\n';
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
