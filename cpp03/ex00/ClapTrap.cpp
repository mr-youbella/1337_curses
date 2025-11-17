/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:10:34 by youbella          #+#    #+#             */
/*   Updated: 2025/11/16 22:10:35 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " created.\n";
}

ClapTrap::ClapTrap(std::string name): name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " created.\n";
}

ClapTrap::ClapTrap(const ClapTrap &clap_trap)
{
	std::cout << "ClapTrap " << clap_trap.name << " was copied to new Object by copy constructor.\n";
	*this = clap_trap;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &clap_trap)
{
	if (name.empty())
		std::cout << "ClapTrap " << clap_trap.name << " was copied to new Object by copy assignment operator.\n";
	else
		std::cout << "ClapTrap " << clap_trap.name << " was copied to " << name << " by copy assignment operator.\n";
	if (this != &clap_trap)
	{
		name = clap_trap.name;
		hit_points = clap_trap.hit_points;
		energy_points = clap_trap.energy_points;
		attack_damage = clap_trap.attack_damage;
	}
	return (*this);
}

void		ClapTrap::attack(const std::string &target)
{
	if (!hit_points)
		std::cout << "ClapTrap " << name << " is destroyed!\n";
	else if (!energy_points)
		std::cout << "ClapTrap " << name << " has no energy left to attack!\n";
	else
	{
		energy_points--;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!\n";
	}
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (!hit_points)
		std::cout << "ClapTrap " << name << " is already destroyed!\n";
	else if (amount >= hit_points)
	{
		hit_points = 0;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and is destroyed!\n";
	}
	else
	{
		hit_points -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!\n";
	}
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (!hit_points)
		std::cout << "ClapTrap " << name << " is destroyed!\n";
	else if (!energy_points)
		std::cout << "ClapTrap " << name << " has no energy left to repair!\n";
	else
	{
		hit_points += amount;
		energy_points--;
		std::cout << "ClapTrap " << name << " repairs itself, gaining " << amount << " hit points!\n";
	}
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed.\n";
}
