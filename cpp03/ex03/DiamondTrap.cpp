/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:23:54 by youbella          #+#    #+#             */
/*   Updated: 2025/11/16 22:42:26 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name"), name("default")
{
	std::cout << "DiamondTrap " << name << " created by Default Constructor.\n";
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), name(name)
{
	std::cout << "DiamondTrap " << name << " created by Constructor.\n";
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamond_trap)
{
	std::cout << "DiamondTrap " << diamond_trap.name << " was copied to new Object by copy constructor\n";
	*this = diamond_trap;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &diamond_trap)
{
	std::cout << "DiamondTrap " << diamond_trap.name << " was copied to " << name << " by copy assignment operator\n";
	if (this != &diamond_trap)
	{
		ClapTrap::operator=(diamond_trap);
		name = diamond_trap.name;
		hit_points = diamond_trap.hit_points;
		energy_points = diamond_trap.energy_points;
		attack_damage = diamond_trap.attack_damage;
	}
	return (*this);
}

void		DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void		DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::name << '\n';
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destroyed by Destructor.\n";
}
