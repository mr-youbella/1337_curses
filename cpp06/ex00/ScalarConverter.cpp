/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:12:03 by youbella          #+#    #+#             */
/*   Updated: 2026/01/29 18:52:41 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "Copy constructor called\n";
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "Copy assignment operator called\n";
}

bool	is_number(std::string const &literal)
{
	int		i = 0;
	bool	point = false;

	if (literal[i] && (literal[i] == '-' || literal[i] == '+'))
		i++;
	if (!literal[i] || literal[i] == '.')
		return (false);
	while (literal[i])
	{
		if (literal[i] == '.')
		{
			if (point)
				return (false);
			point = true;
			i++;
		}
		if (!(literal[i] >= '0' && literal[i] <= '9'))
		{
			if (literal[i] == 'f' && (literal[i - 1] >= '0' && literal[i - 1] <= '9') && !literal[i + 1])
				i++;
			else
				return (false);
		}
		else
			i++;
	}
	return (true);
}

void	ScalarConverter::convert(std::string const &literal)
{
	errno = 0;
	char	*end = NULL;
	double 	integer = std::strtod(literal.c_str(), &end);
	bool	is_num = is_number(literal);
	bool	is_pseudo = literal == "nan" || literal == "nanf" || literal == "-inf" || literal == "-inff" || literal == "+inf" || literal == "+inff";

	// Char
	if (literal.length() == 1 && !(literal[0] >= '0' && literal[0] <= '9'))
	{
		if (literal[0] >= 32 && literal[0] <= 126)
			std::cout << "char: '" << static_cast<char>(literal[0]) << "'\n";
		else
			std::cout << "char: " << "Non displayable\n";
	}
	else if (is_num)
	{
		if (errno == ERANGE || !(integer >= 0 && integer <= 255))
			std::cout << "char: " << "impossible" << '\n';
		else if (!(integer >= 32 && integer <= 126))
			std::cout << "char: " << "Non displayable\n";
		else
			std::cout << "char: '" << static_cast<char>(integer) << "'\n";
	}
	else
		std::cout << "char: " << "impossible" << '\n';
	// Int
	if (literal.length() == 1 && !(literal[0] >= '0' && literal[0] <= '9'))
		std::cout << "int: " << static_cast<int>(literal[0]) << "\n";
	else if (is_num)
	{
		if (errno == ERANGE || integer > INT_MAX || integer < INT_MIN)
			std::cout << "int: " << "impossible" << '\n';
		else
			std::cout << "int: " << static_cast<int>(integer) << '\n';
	}
	else
		std::cout << "int: " << "impossible" << '\n';
	// Float
	if (literal.length() == 1 && !(literal[0] >= '0' && literal[0] <= '9'))
		std::cout << "float: " << static_cast<float>(literal[0]) << ".0f\n";
	else if (is_num || is_pseudo)
	{
		if (is_pseudo)
		{
			if (literal == "-inf" || literal == "+inf" || literal == "+inff" || literal == "-inff")
				std::cout << "float: " << literal[0] << "inff" << '\n';
			else
				std::cout << "float: " << "nanf" << '\n';
		}
		else if (errno == ERANGE)
			std::cout << "float: " << "impossible" << '\n';
		else
		{
			if (integer == static_cast<long long>(integer))
				std::cout << "float: " << static_cast<float>(integer) << ".0f\n";
			else
				std::cout << "float: " << static_cast<float>(integer) << "f\n";
		}
	}
	else
		std::cout << "float: " << "impossible" << '\n';
	// Double
	if (literal.length() == 1 && !(literal[0] >= '0' && literal[0] <= '9'))
		std::cout << "double: " << static_cast<double>(literal[0]) << ".0\n";
	else if (is_num || is_pseudo)
	{
		if (is_pseudo)
		{
			if (literal == "-inf" || literal == "+inf" || literal == "+inff" || literal == "-inff")
				std::cout << "double: " << literal[0] << "inf" << '\n';
			else
				std::cout << "double: " << "nan" << '\n';
		}
		else if (errno == ERANGE)
				std::cout << "double: " << "impossible" << '\n';
		else
		{
			if (integer == static_cast<long long>(integer))
				std::cout << "double: " << static_cast<double>(integer) << ".0\n";
			else
				std::cout << "double: " << static_cast<double>(integer) << '\n';
		}
	}
	else
		std::cout << "double: " << "impossible" << '\n';
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called\n";
}
