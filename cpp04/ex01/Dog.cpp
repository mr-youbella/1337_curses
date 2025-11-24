	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:34 by youbella          #+#    #+#             */
/*   Updated: 2025/11/23 10:06:07 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	std::cout << "Constructor Dog called\n";
	type = "Dog";
	brain = new Brain;
}

Dog::Dog(const Dog &other): Animal(other)
{
	std::cout << "Copy constructor Dog called\n";
	brain = new Brain(*other.brain);
}

Dog		&Dog::operator=(const Dog &other)
{
	std::cout << "Copy assignment operator Dog called\n";
	Animal::operator=(other);
	if (this != &other)
	{
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "3aaaaaw 3aaaaaw\n";
}

Dog::~Dog(void)
{
	std::cout << "Destructor Dog called\n";
	delete brain;
}
