/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:21:34 by youbella          #+#    #+#             */
/*   Updated: 2025/10/27 11:42:39 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	if (type.empty())
		type = "unknown weapon";
	this->type = type;
}

const std::string	&Weapon::getType(void) const
{
	return (type);
}

void	Weapon::setType(std::string newType)
{
	if (newType.empty())
		newType = "unknown weapon";
	this->type = newType;
}

Weapon::~Weapon(void)
{
	return ;
}
