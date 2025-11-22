/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:19:58 by youbella          #+#    #+#             */
/*   Updated: 2025/11/21 17:56:58 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called\n";
}

Ice::Ice(const Ice &other)
{
	std::cout << "Ice copy constructor called\n";
	*this = other;
}

Ice & Ice::operator=(const Ice &other)
{
	std::cout << "Ice assignment operator called\n";
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

AMateria* Ice::clone() const
{
	std::cout << "Ice clone called\n";
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice::~Ice()
{
	std::cout << "Ice destructor called\n";
}
