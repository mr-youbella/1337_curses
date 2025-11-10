/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 23:38:25 by youbella          #+#    #+#             */
/*   Updated: 2025/11/10 14:29:42 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::bit = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int value)
{
	std::cout << "Int constructor called\n";
	_value = value << bit;
}

Fixed::Fixed(float value)
{
	std::cout << "Float constructor called\n";
	_value = roundf(value * (1 << bit));
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

float	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << bit));
}

int		Fixed::toInt(void) const
{
	return (_value >> bit);
}

bool		Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}

bool		Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}

bool		Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}

bool		Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}

bool		Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}

bool			Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}

Fixed			Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed			Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed			Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed			Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed			&Fixed::operator++()
{
	_value++;
	return (*this);
}

Fixed			Fixed::operator++(int)
{
	Fixed temp(*this);

	_value++;
	return (temp);
}

Fixed			&Fixed::operator--()
{
	_value--;
	return (*this);
}

Fixed			Fixed::operator--(int)
{
	Fixed temp(*this);

	_value--;
	return (temp);
}

Fixed			&Fixed::min(Fixed &a, Fixed &b)
{
	if (a._value <= b._value)
		return (a);
	return (b);
}

const Fixed		&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._value <= b._value)
		return (a);
	return (b);
}

Fixed			&Fixed::max(Fixed &a, Fixed &b)
{
	if (a._value >= b._value)
		return (a);
	return (b);
}

const Fixed		&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._value >= b._value)
		return (a);
	return (b);
}

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}
