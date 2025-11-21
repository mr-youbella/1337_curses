/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:21 by youbella          #+#    #+#             */
/*   Updated: 2025/11/20 17:49:49 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("Lion")
{
	std::cout << "Constructor Animal called\n";
}

Animal::Animal(const Animal &other)
{
	std::cout << "Copy constructor Animal called\n";
	*this = other;
}

Animal		&Animal::operator=(const Animal &other)
{
	std::cout << "Copy assignment operator Animal called\n";
	if (this != &other)
		type = other.type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (type);
}

Animal::~Animal(void)
{
	std::cout << "Destructor Animal called\n";
}
