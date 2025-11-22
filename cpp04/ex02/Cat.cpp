/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:26 by youbella          #+#    #+#             */
/*   Updated: 2025/11/21 23:42:45 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	std::cout << "Constructor Cat called\n";
	type = "Cat";
	brain = new Brain;
}
Cat::Cat(const Cat &other)
{
	std::cout << "Copy constructor Cat called\n";
	*this = other;
}
Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Copy assignment operator Cat called\n";
	Animal::operator=(other);
	if (this != &other)
	{
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}
void	Cat::makeSound() const
{
	std::cout << "Meowwwwwwwwwwwwww\n";
}

Cat::~Cat(void)
{
	std::cout << "Destructor Cat called\n";
	delete brain;
}
