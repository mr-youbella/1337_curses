/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 23:38:25 by youbella          #+#    #+#             */
/*   Updated: 2025/10/19 17:51:46 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::bit = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &copyFixed)
{
	std::cout << "Copy constructor called\n";
	*this = copyFixed;
}

Fixed	&Fixed::operator=(const Fixed &copyFixed)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &copyFixed)
		this->_value = copyFixed.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";	
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

Fixed::Fixed(int value)
{
	std::cout << "Int constructor called\n";
	_value = value << bit;
}

Fixed::Fixed(float value)
{
	std::cout << "Float constructor called\n";
	_value = roundf(value * (1 << this->bit));
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << bit));
}

int		Fixed::toInt(void) const
{
	return (_value >> bit);
}

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed::~Fixed(void)
{
	std::cout << "   \033[32m   Destructor called\n";
}
