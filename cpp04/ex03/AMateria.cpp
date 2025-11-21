/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:20:00 by youbella          #+#    #+#             */
/*   Updated: 2025/11/20 16:22:32 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(): type("default")
{
    std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(const std::string &type): type(type)
{
    std::cout << "AMateria constructor called for " << type << "\n";
}

AMateria::AMateria(const AMateria &other)
{
    std::cout << "AMateria copy constructor called\n";
	*this = other;
}

AMateria & AMateria::operator=(const AMateria &other)
{
    std::cout << "AMateria assignment operator called\n";
	if (this != &other)
		type = other.type;
    return (*this);
}

const std::string &AMateria::getType() const
{
    return (type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses unknown materia on " << target.getName() << " *\n";
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called for " << type << "\n";
}
