/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:58:27 by youbella          #+#    #+#             */
/*   Updated: 2026/01/03 18:50:26 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <ctime>

// void	f()
// {
// 	system("leaks intern");
// }

int main(void)
{
	// atexit(f);
	std::srand(std::time(NULL));
	try
	{
		Intern		intern_alex;
		Bureaucrat	leader("leader", 1);
		AForm		*rrf;

		rrf = intern_alex.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			leader.signForm(*rrf);
			leader.executeForm(*rrf);
			delete rrf;
		}
	}
	catch (std::exception &e)
	{
	    std::cout << "Unexpected Error: " << e.what() << '\n';
    }
	return (0);
}
