/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:58:27 by youbella          #+#    #+#             */
/*   Updated: 2026/01/01 18:01:57 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main(void)
{
	std::srand(std::time(NULL));
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
		boss.executeForm(robot);

		intern.executeForm(pardon);

		PresidentialPardonForm	newPardon("Target");
		boss.executeForm(newPardon);
	}
	catch (std::exception &e)
	{
	    std::cout << "Unexpected Error: " << e.what() << std::endl;
    }
	return (0);
}
