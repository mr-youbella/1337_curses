/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:16:25 by youbella          #+#    #+#             */
/*   Updated: 2025/11/24 21:38:37 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): name("Unknown")
{
	std::cout << "Character default constructor called\n";
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const std::string &name): name(name)
{
	std::cout << "Character parameterized constructor called for " << name << "\n";
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &other): name(other.name)
{
	std::cout << "Character copy constructor called\n";
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i] != NULL)
			inventory[i] = other.inventory[i]->clone();
	    else
			inventory[i] = NULL;
	}
}

Character	&Character::operator=(const Character &other)
{
	std::cout << "Character assignment operator called\n";
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
		    if (inventory[i] != NULL)
			{
				delete inventory[i];
				inventory[i] = NULL;
			}
		} 
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i] != NULL)
				inventory[i] = other.inventory[i]->clone();
		}
	}
	return (*this);
}

const	std::string &Character::getName() const
{
	return name;
}

void	Character::equip(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << name << ": Cannot equip NULL materia\n";
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << name << " equipped " << m->getType() << " at slot " << i << "\n";
			return;
		}
	}
	std::cout << name << ": Inventory full! Cannot equip " << m->getType() << "\n";
}

void 	Character::unequip(int id)
{
	if (id < 0 || id >= 4)
	{
		std::cout << name << ": Invalid slot index " << id << "\n";
		return;
	}  
	if (inventory[id] != NULL)
	{
		std::cout << name << " unequipped " << inventory[id]->getType() << " from slot " << id << "\n";
		delete inventory[id];
		inventory[id] = NULL;
	}
	else
		std::cout << name << ": Slot " << id << " is already empty\n";
}

void Character::use(int id, ICharacter &target)
{
	if (id < 0 || id >= 4)
	{
		std::cout << name << ": Invalid slot index " << id << "\n";
		return;
	}
	if (inventory[id] != NULL)
		inventory[id]->use(target);
	else
		std::cout << name << ": Slot " << id << " is empty\n";
}

Character::~Character()
{
	std::cout << "Character destructor called for " << name << "\n";
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
}
