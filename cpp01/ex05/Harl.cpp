/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:46:36 by youbella          #+#    #+#             */
/*   Updated: 2025/10/27 11:32:17 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

void	Harl::debug(void)
{
	std::cout << "I added one more console.log… and now the page exploded.\n";
}
void	Harl::info(void)
{
	std::cout << "Loaded 100 images… is slowly i think.\n";
}
void	Harl::warning(void)
{
	std::cout << "You forgot a semicolon… hmmm.\n";
}
void	Harl::error(void)
{
	std::cout << "Page crashed… Ctrl+Z doesn't work here.\n";
}

void	Harl::complain(std::string level)
{
	void	(Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string		levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int				i;

	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return ;
		}
		i++;
	}
	std::cout << "[" << level << "]" << " is not recognized!\n";
}

Harl::~Harl(void)
{
	return ;
}
