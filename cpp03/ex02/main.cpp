/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:10:59 by youbella          #+#    #+#             */
/*   Updated: 2025/11/16 22:11:00 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap	a;

	a.takeDamage(1);
	for (int i = 0; i < 10; i++)
		a.attack("younes");
	a.attack("younes");
	for (int i = 0; i < 9; i++)
		a.takeDamage(1);
	a.beRepaired(10);
	a.takeDamage(1);
	a.highFivesGuys();
    return 0;
}
