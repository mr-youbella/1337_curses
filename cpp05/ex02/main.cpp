/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:58:27 by youbella          #+#    #+#             */
/*   Updated: 2026/01/20 22:15:41 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat				boss("Boss", 1);
		Bureaucrat				intern("Intern", 150);
	
		ShrubberyCreationForm	shrub("Home");
		RobotomyRequestForm		robot("Bender");
		PresidentialPardonForm	pardon("Criminal");

		boss.signForm(shrub);
		boss.executeForm(shrub);

		boss.signForm(robot);
		for (int i = 1; i <= 6; i++)
		{
			try
			{
				robot.execute(boss);
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}

		intern.executeForm(pardon);

		PresidentialPardonForm	newPardon("Target");
		boss.executeForm(newPardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected Error: " << e.what() << '\n';
	}
	return (0);
}
