/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:26 by youbella          #+#    #+#             */
/*   Updated: 2025/11/20 17:48:34 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	std::cout << "Constructor Cat called\n";
	type = "Cat";
}
Cat::Cat(const Cat &other): Animal(other)
{
	std::cout << "Copy constructor Cat called\n";
	*this = other;
}
Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Copy assignment operator Cat called\n";
	Animal::operator=(other);
	return (*this);
}
void	Cat::makeSound(void) const
{
	std::cout << "Meowwwwwwwww\n";
}

Cat::~Cat(void)
{
	std::cout << "Destructor Cat called\n";
}
