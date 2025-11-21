#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(): name("Unknown")
{
    std::cout << "Character default constructor called\n";
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const std::string &name): name(name)
{
    std::cout << "Character parameterized constructor called for " << name << "\n";
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character &other): name(other.name)
{
    std::cout << "Character copy constructor called\n";
    for (int i = 0; i < 4; i++)
	{
        if (other._inventory[i] != NULL)
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character & Character::operator=(const Character &other)
{
    std::cout << "Character assignment operator called\n";
    if (this != &other)
	{
        name = other.name;
        for (int i = 0; i < 4; i++)
		{
            if (_inventory[i] != NULL)
			{
                delete _inventory[i];
                _inventory[i] = NULL;
            }
        } 
        for (int i = 0; i < 4; i++)
		{
            if (other._inventory[i] != NULL)
                _inventory[i] = other._inventory[i]->clone();
        }
    }
    return (*this);
}

const std::string &Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (m == NULL)
	{
        std::cout << name << ": Cannot equip NULL materia\n";
        return;
    }
    
    for (int i = 0; i < 4; i++)
	{
        if (_inventory[i] == NULL)
		{
            _inventory[i] = m;
            std::cout << name << " equipped " << m->getType() << " at slot " << i << "\n";
            return;
        }
    }
    std::cout << name << ": Inventory full! Cannot equip " << m->getType() << "\n";
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
	{
        std::cout << name << ": Invalid slot index " << idx << "\n";
        return;
    }  
    if (_inventory[idx] != NULL)
	{
        std::cout << name << " unequipped " << _inventory[idx]->getType() << " from slot " << idx << "\n";
        _inventory[idx] = NULL;
    }
	else
        std::cout << name << ": Slot " << idx << " is already empty\n";
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
	{
        std::cout << name << ": Invalid slot index " << idx << "\n";
        return;
    }
    if (_inventory[idx] != NULL)
        _inventory[idx]->use(target);
	else
        std::cout << name << ": Slot " << idx << " is empty\n";
}

Character::~Character()
{
    std::cout << "Character destructor called for " << name << "\n";
    for (int i = 0; i < 4; i++)
	{
        if (_inventory[i] != NULL)
            delete _inventory[i];
    }
}
