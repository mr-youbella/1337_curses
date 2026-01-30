/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:12:03 by youbella          #+#    #+#             */
/*   Updated: 2026/01/30 11:45:55 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <cmath>
#include <limits>

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
	std::cout << "Copy constructor called\n";
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	std::cout << "Copy assignment operator called\n";
	return (*this);
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
			if (literal[i] == 'f' && i > 0 && (literal[i - 1] >= '0' && literal[i - 1] <= '9') && !literal[i + 1])
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
	float	f = static_cast<float>(integer);
	if (literal.length() == 1 && !(literal[0] >= '0' && literal[0] <= '9'))
		std::cout << "float: " << static_cast<float>(literal[0]) << ".0f\n";
	else if (is_num || is_pseudo)
	{
		if (errno == ERANGE)
				std::cout << "float: " << "impossible" << '\n';
		else if (f == std::numeric_limits<float>::infinity() || f == -std::numeric_limits<float>::infinity())
    	    std::cout << "float: " << (f < 0 ? "-inff\n" : "+inff\n");
		else if (is_pseudo)
		{
			if (literal == "-inf" || literal == "+inf" || literal == "+inff" || literal == "-inff")
				std::cout << "float: " << literal[0] << "inff" << '\n';
			else
				std::cout << "float: " << "nanf" << '\n';
		}
		else
		{
			std::cout << "float: ";
   			if (static_cast<long long>(f) != integer)
   			    std::cout << std::scientific << std::setprecision(0) << f << "f\n";
   			else
   			    std::cout << std::fixed << std::setprecision(f == static_cast<long long>(f) ? 1 : 6) << f << "f\n";
   			std::cout.unsetf(std::ios::floatfield);
		}
	}
	else
		std::cout << "float: " << "impossible" << '\n';
	// Double
	double	d = static_cast<double>(integer);
	if (literal.length() == 1 && !(literal[0] >= '0' && literal[0] <= '9'))
		std::cout << "double: " << static_cast<double>(literal[0]) << ".0\n";
	else if (is_num || is_pseudo)
	{
		if (errno == ERANGE)
				std::cout << "double: " << "impossible" << '\n';
		else if (d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity())
    	    std::cout << "double: " << (d < 0 ? "-inf\n" : "+inf\n");
		else if (is_pseudo)
		{
			if (literal == "-inf" || literal == "+inf" || literal == "+inff" || literal == "-inff")
				std::cout << "double: " << literal[0] << "inf" << '\n';
			else
				std::cout << "double: " << "nan" << '\n';
		}
		else
		{
			std::cout << "double: ";
  			if (static_cast<long long>(integer) != integer)
  			    std::cout << std::scientific << std::setprecision(0) << integer << "\n";
  			else
  			    std::cout << std::fixed << std::setprecision(1) << integer << "\n";
  			std::cout.unsetf(std::ios::floatfield);
		}
	}
	else
		std::cout << "double: " << "impossible" << '\n';
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called\n";
}
