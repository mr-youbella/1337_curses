/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:58:27 by youbella          #+#    #+#             */
/*   Updated: 2026/01/21 14:02:04 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Intern		intern_alex;
		Bureaucrat	leader("leader", 1);
		AForm		*rrf;

		try
		{
			rrf = intern_alex.makeForm("robotomy request", "Bender");
			leader.signForm(*rrf);
			leader.executeForm(*rrf);
			delete rrf;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << '\n';
		}
	}
	catch (std::exception &e)
	{
	    std::cout << "Unexpected Error: " << e.what() << '\n';
    }
	return (0);
}
