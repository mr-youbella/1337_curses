#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure")
{
    std::cout << "Cure constructor called\n";
}

Cure::Cure(const Cure &other): AMateria(other)
{
    std::cout << "Cure copy constructor called\n";
}

Cure & Cure::operator=(const Cure &other)
{
    std::cout << "Cure assignment operator called\n";
    if (this != &other)
        AMateria::operator=(other);
    return (*this);
}

AMateria* Cure::clone() const
{
    std::cout << "Cure clone called\n";
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

Cure::~Cure()
{
    std::cout << "Cure destructor called\n";
}
