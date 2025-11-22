/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:26 by youbella          #+#    #+#             */
/*   Updated: 2025/11/21 23:37:13 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	std::cout << "Constructor WrongCat called\n";
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other)
{
	std::cout << "Copy constructor WrongCat called\n";
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	std::cout << "Copy assignment operator WrongCat called\n";
	WrongAnimal::operator=(other);
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meowwwwwwwww\n";
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor WrongCat called\n";
}
