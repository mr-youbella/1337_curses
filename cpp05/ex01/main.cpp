/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:58:27 by youbella          #+#    #+#             */
/*   Updated: 2026/01/03 18:30:55 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat	boss("The Boss", 1);
		Bureaucrat	intern("The Intern", 150);
		Form 		form("Tax Return", 50, 100);

		std::cout << form << '\n';

		std::cout << "--- Intern tries to sign ---" << '\n';
		intern.signForm(form);

		std::cout << "\n--- Boss tries to sign ---" << '\n';
		boss.signForm(form);

		std::cout << "\n--- Final Status ---" << '\n';
		std::cout << form << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << "Main Exception: " << e.what() << '\n';
	}
	return 0;
}
