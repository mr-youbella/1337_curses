/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:10:44 by youbella          #+#    #+#             */
/*   Updated: 2025/11/16 22:26:44 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap " << name << " created.\n";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " created.\n";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scav_trap): ClapTrap(scav_trap)
{
	std::cout << "ScavTrap " << scav_trap.name << " was copied to new Object by copy constructor\n";
	*this = scav_trap;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &scav_trap)
{
	std::cout << "ScavTrap " << scav_trap.name << " was copied to " << name << " by copy assignment operator\n";
	if (this != &scav_trap)
	{
		ClapTrap::operator=(scav_trap);
		name = scav_trap.name;
		hit_points = scav_trap.hit_points;
		energy_points = scav_trap.energy_points;
		attack_damage = scav_trap.attack_damage;
	}
	return (*this);
}

void		ScavTrap::attack(const std::string &target)
{
	if (!hit_points)
		std::cout << "ScavTrap " << name << " is destroyed!\n";
	else if (!energy_points)
		std::cout << "ScavTrap " << name << " has no energy left to attack!\n";
	else
	{
		energy_points--;
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!\n";
	}
}

void		ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate Keeper mode.\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destroyed.\n";
}
