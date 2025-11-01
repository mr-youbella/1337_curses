/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:26:36 by youbella          #+#    #+#             */
/*   Updated: 2025/10/17 17:59:55 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	if (name.empty())
		name = "ha";
	this->name = name;
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << '\n';
}

HumanA::~HumanA(void)
{
	return ;
}
