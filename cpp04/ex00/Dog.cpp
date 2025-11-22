/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:26 by youbella          #+#    #+#             */
/*   Updated: 2025/11/21 23:30:54 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	std::cout << "Constructor Dog called\n";
	type = "Dog";
}

Dog::Dog(const Dog &other)
{
	std::cout << "Copy constructor Dog called\n";
	*this = other;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Copy assignment operator Dog called\n";
	Animal::operator=(other);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "3aaaw 3aaaaw\n";
}

Dog::~Dog(void)
{
	std::cout << "Destructor Dog called\n";
}
