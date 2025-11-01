/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:43:57 by youbella          #+#    #+#             */
/*   Updated: 2025/10/22 23:49:28 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	Weapon	knife("hard knife");
	HumanA	ha("youbella", knife);
	ha.attack();
	knife.setType("small knife");
	HumanB	hb("younes");
	hb.setWeapon(knife);
	hb.attack();
}
