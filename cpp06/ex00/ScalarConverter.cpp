/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:12:03 by youbella          #+#    #+#             */
/*   Updated: 2026/01/31 13:12:16 by youbella         ###   ########.fr       */
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

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	std::cout << "Copy assignment operator called\n";
	return (*this);
}

bool			checkArg(const std::string &literal)
{
	size_t		i = 0;
	bool		hasPoint = false;
	bool		hasF = false;
	std::string pseudo[] = {"nan", "nanf", "inf", "+inf", "-inf", "inff", "+inff", "-inff"};

	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return (true);
	for (; i < 8; i++)
	{
		if (literal == pseudo[i])
			return (true);
	}
	i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return (false);
	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasPoint || hasF)
				return (false);
			hasPoint = true;
		}
		else if (literal[i] == 'f')
		{
			if (hasF || i != literal.length() - 1)
				return (false);
			hasF = true;
		}
		else if (!std::isdigit(literal[i]))
			return (false);
	}
	return (true);
}

bool			isChar(const std::string &literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]))
        return (true);
    return (false);
}

void			printChar(const std::string &literal)
{
	char c = literal[0];

	if (std::isprint(c))
	    std::cout << "char: '" << c << "'\n";
	else
	    std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(c) << '\n';
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << '\n';
}

bool			isInt(const std::string &literal)
{
    size_t	i = 0;
    long	val = std::atol(literal.c_str());

    if (literal[i] == '-' || literal[i] == '+')
        i++;
    if (i == literal.length())
        return (false);
    for (; i < literal.length(); i++)
    {
        if (!std::isdigit(literal[i]))
            return (false);
    }
    if (val > INT_MAX || val < INT_MIN)
        return (false);
    return (true);
}

void			printInt(const std::string &literal)
{
	long	temp = std::atol(literal.c_str());
	int		i = static_cast<int>(temp);

	std::cout << "char: ";
	if (temp < 0 || temp > 127)
	    std::cout << "impossible\n";
	else if (!std::isprint(i))
	    std::cout << "Non displayable\n";
	else
	    std::cout << "'" << static_cast<char>(i) << "'\n";
	std::cout << "int: " << i << '\n';
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << '\n';
}

bool			isFloat(const std::string &literal)
{
    size_t	i = 0;
    bool	hasPoint = false;

    if (literal == "nanf" || literal == "inff" || literal == "+inff" || literal == "-inff")
        return (true);
    if (literal[literal.length() - 1] != 'f')
        return (false);
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    if (i == literal.length() - 1)
        return (false);
    for (; i < literal.length() - 1; i++)
    {
        if (literal[i] == '.')
        {
            if (hasPoint)
				return (false);
            hasPoint = true;
        }
        else if (!std::isdigit(literal[i]))
            return (false);
    }
    return (true);
}

void			printFloat(const std::string &literal)
{
	float	f = static_cast<float>(std::atof(literal.c_str()));

	std::cout << "char: ";
	if (literal == "nanf" || literal == "inff" || literal == "+inff" || literal == "-inff" || f < 0 || f > 127)
	    std::cout << "impossible\n";
	else if (!std::isprint(static_cast<int>(f)))
	    std::cout << "Non displayable\n";
	else
	    std::cout << "'" << static_cast<char>(f) << "'\n";
	std::cout << "int: ";
	if (literal == "nanf" || f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
	    std::cout << "impossible\n";
	else
	    std::cout << static_cast<int>(f) << '\n';
	if (f < 1e6f && f > -1e6f && f == static_cast<long>(f)) 
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << '\n';
    }
    else 
    {
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << static_cast<double>(f) << '\n';
    }
}

bool			isDouble(const std::string &literal)
{
    size_t	i = 0;

	if (literal == "nan" || literal == "inf" || literal == "+inf" || literal == "-inf")
		return (true);
	if (literal[literal.length() - 1] == 'f')
		return (false);
	if (literal[i] == '+' || literal[i] == '-') i++;
	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
			continue ;
		if (!std::isdigit(literal[i]))
			return (false);
	}
	return (true);
}

void			printDouble(const std::string &literal)
{
    double	d = std::strtod(literal.c_str(), NULL);
    float	f = static_cast<float>(d);

    std::cout << "char: ";
    if (literal == "nan" || literal == "inf" || literal == "+inf" || literal == "-inf" || d < 0 || d > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(d) << "'\n";
    std::cout << "int: ";
    if (literal == "nan" || d > INT_MAX || d < INT_MIN)
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(d) << '\n';
	std::cout << "float: ";
	if (d < 1e6 && d > -1e6 && d == static_cast<long>(d)) 
    {
        std::cout << std::fixed << std::setprecision(1) << f << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << '\n';
    }
    else 
    {
        std::cout.unsetf(std::ios_base::fixed); 
        std::cout << f << "f\n";
        std::cout << "double: " << d << '\n';
    }
}

void			ScalarConverter::convert(const std::string &literal)
{
	if (!checkArg(literal))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return ;
	}
	if (isChar(literal))
	{
		printChar(literal);
		return ;
	}
	if (isInt(literal))
	{
		printInt(literal);
		return ;
	}
	if (isFloat(literal))
	{
		printFloat(literal);
		return ;
	}
	if (isDouble(literal))
	{
		printDouble(literal);
		return ;
	}
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called\n";
}
