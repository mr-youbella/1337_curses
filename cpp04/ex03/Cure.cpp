/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:16:48 by youbella          #+#    #+#             */
/*   Updated: 2025/11/21 18:40:15 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure constructor called\n";
}

Cure::Cure(const Cure &other): AMateria(other)
{
	std::cout << "Cure copy constructor called\n";
}

Cure		&Cure::operator=(const Cure &other)
{
	std::cout << "Cure assignment operator called\n";
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

AMateria	*Cure::clone() const
{
	std::cout << "Cure clone called\n";
	return (new Cure(*this));
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

Cure::~Cure()
{
	std::cout << "Cure destructor called\n";
}
