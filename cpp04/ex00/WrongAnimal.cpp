/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:21 by youbella          #+#    #+#             */
/*   Updated: 2025/11/20 17:53:34 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("Lion")
{
	std::cout << "Constructor WrongAnimal called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "Copy constructor WrongAnimal called\n";
	*this = other;
}

WrongAnimal		&WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "Copy assignment operator WrongAnimal called\n";
	if (this != &other)
		type = other.type;
	return (*this);
}

void		WrongAnimal::makeSound(void) const
{
	std::cout << "Roarrrrrrrrrrrrrr\n";
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor WrongAnimal called\n";
}
