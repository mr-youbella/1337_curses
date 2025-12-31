/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:58:27 by youbella          #+#    #+#             */
/*   Updated: 2025/12/31 11:00:09 by youbella         ###   ########.fr       */
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
		std::cerr << "Main Exception: " << e.what() << '\n';
	}
	return 0;
}