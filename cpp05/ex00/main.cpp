/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:59:56 by youbella          #+#    #+#             */
/*   Updated: 2026/01/03 18:24:06 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "--- Test 1" << '\n';
	try
	{
		Bureaucrat younes("younes", 2);
		std::cout << younes;
		younes.incrementGrade();
		std::cout << "After increment: " << younes;
		younes.decrementGrade();
		std::cout << "After decrement: " << younes;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected Exception: " << e.what() << '\n';
	}
	//----------------------------------------------------------------------------------------
	std::cout << "\n--- Test 2" << '\n';
	try 
	{
		Bureaucrat boss("Boss", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught Exception: " << e.what() << '\n';
	}
	//----------------------------------------------------------------------------------------
	std::cout << "\n--- Test 3" << '\n';
	try 
	{
		Bureaucrat youbella("youbella", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught Exception: " << e.what() << '\n';
	}
	//----------------------------------------------------------------------------------------
	std::cout << "\n--- Test 4" << '\n';
	try 
	{
		Bureaucrat top("Top", 1);
		std::cout << top;
		top.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Caught Exception: " << e.what() << '\n';
	}
	//----------------------------------------------------------------------------------------
	std::cout << "\n--- Test 5" << '\n';
	try 
	{
		Bureaucrat leader("leader", 150);
		std::cout << leader;
		leader.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Caught Exception: " << e.what() << '\n';
	}
	return (0);
}
