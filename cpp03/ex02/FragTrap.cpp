/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:10:53 by youbella          #+#    #+#             */
/*   Updated: 2025/11/16 22:29:20 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap " << name << " created by Default Constructor.\n";
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap " << name << " created by Constructor.\n";
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &frag_trap): ClapTrap(frag_trap)
{
	std::cout << "FragTrap " << frag_trap.name << " was copied to new Object by copy constructor\n";
	*this = frag_trap;
}

FragTrap	&FragTrap::operator=(const FragTrap &frag_trap)
{
	std::cout << "FragTrap " << frag_trap.name << " was copied to " << name << " by copy assignment operator\n";
	if (this != &frag_trap)
	{
		ClapTrap::operator=(frag_trap);
		name = frag_trap.name;
		hit_points = frag_trap.hit_points;
		energy_points = frag_trap.energy_points;
		attack_damage = frag_trap.attack_damage;
	}
	return (*this);
}

void		FragTrap::attack(const std::string &target)
{
	if (!hit_points)
		std::cout << "FragTrap " << name << " is destroyed!\n";
	else if (!energy_points)
		std::cout << "FragTrap " << name << " has no energy left to attack!\n";
	else
	{
		energy_points--;
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!\n";
	}
}

void		FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests a positive high five!\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destroyed by Destructor.\n";
}
