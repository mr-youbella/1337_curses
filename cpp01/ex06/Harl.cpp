/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:46:36 by youbella          #+#    #+#             */
/*   Updated: 2025/10/27 11:33:34 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

enum Level {DEBUG, INFO, WARNING, ERROR, NOTHING};

Level	getLevel(std::string level)
{
	if (level == "DEBUG")
		return (DEBUG);
	else if (level == "INFO")
		return (INFO);
	else if (level == "WARNING")
		return (WARNING);
	else if (level == "ERROR")
		return (ERROR);
	return (NOTHING);
}

Harl::Harl(void)
{
	return ;
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n" << "I added one more console.log… and now the page exploded.\n";
}
void	Harl::info(void)
{
	std::cout << "[ INFO ]\n" << "Loaded 100 images… is slowly i think.\n";
}
void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\n" << "You forgot a semicolon… hmmm.\n";
}
void	Harl::error(void)
{
	std::cout << "[ ERROR ]\n" << "Page crashed… Ctrl+Z doesn't work here.\n";
}

void	Harl::complain(std::string level)
{
	switch (getLevel(level))
	{
		case DEBUG: this->debug();
		case INFO: this->info();
		case WARNING: this->warning();
		case ERROR: this->error();
		break ;
		default: std::cout << "[" << level << "]" << " is not recognized!\n";
	}
}

Harl::~Harl(void)
{
	return ;
}
