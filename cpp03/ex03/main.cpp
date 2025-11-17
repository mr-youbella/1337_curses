/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:29:57 by youbella          #+#    #+#             */
/*   Updated: 2025/11/16 22:48:54 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	a;
	DiamondTrap	b("younes");

	a.attack("youbella");
	a.whoAmI();
	a.highFivesGuys();
	a.guardGate();

	b = a;
	std::cout << "-----------------\n";
	b.whoAmI();
	std::cout << "-----------------\n";
}
