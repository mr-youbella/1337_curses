/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 23:38:25 by youbella          #+#    #+#             */
/*   Updated: 2025/10/18 18:03:18 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::bit = 8;

Fixed::Fixed(void) : value(0)
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
		this->value = copyFixed.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";	
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}
