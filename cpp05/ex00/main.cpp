/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:59:56 by youbella          #+#    #+#             */
/*   Updated: 2026/01/01 17:50:43 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "--- Test 1: Standard Success ---" << std::endl;
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
	    std::cout << "Unexpected Exception: " << e.what() << std::endl;
	}
	//----------------------------------------------------------------------------------------
    std::cout << "\n--- Test 2: Grade Too High (Constructor) ---" << std::endl;
	try 
	{
		Bureaucrat boss("Boss", 0);
	}
	catch (std::exception &e) 
	{
		std::cout << "Caught Exception: " << e.what() << std::endl;
	}
	//----------------------------------------------------------------------------------------
	std::cout << "\n--- Test 3: Grade Too Low (Constructor) ---" << std::endl;
	try 
	{
		Bureaucrat youbella("youbella", 151);
	}
	catch (std::exception &e) 
	{
		std::cout << "Caught Exception: " << e.what() << std::endl;
	}
	//----------------------------------------------------------------------------------------
	std::cout << "\n--- Test 4: Grade Too High (Increment) ---" << std::endl;
	try 
	{
		Bureaucrat top("Top", 1);
		std::cout << top;
		top.incrementGrade();
	}
	catch (std::exception &e) 
	{
		std::cout << "Caught Exception: " << e.what() << std::endl;
	}
	//----------------------------------------------------------------------------------------
	std::cout << "\n--- Test 5: Grade Too Low (Decrement) ---" << std::endl;
	try 
	{
		Bureaucrat leader("leader", 150);
		std::cout << leader;
		leader.decrementGrade();
	}
	catch (std::exception &e) 
	{
		std::cout << "Caught Exception: " << e.what() << std::endl;
	}
    return (0);
}
