/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:47:00 by youbella          #+#    #+#             */
/*   Updated: 2026/03/08 00:58:28 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	try
	{
		std::cout << "Searching for 20 in vector: ";
		std::vector<int>::iterator it = easyfind(v, 20);
		std::cout << "Found " << *it << '\n';

		std::cout << "Searching for 50 in vector: ";
		easyfind(v, 50);
	} 
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-------------------\n";

	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	try
	{
		std::cout << "Searching for 3 in list: ";
		std::list<int>::iterator it = easyfind(l, 3);
		std::cout << "Found " << *it << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
