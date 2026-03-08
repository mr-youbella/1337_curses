/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:26:42 by youbella          #+#    #+#             */
/*   Updated: 2026/03/08 02:12:04 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <ctime>

int main()
{
	std::cout << "--- Subject Test ---\n";
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << '\n';
	std::cout << sp.longestSpan() << '\n';
	std::cout << "--- 10,000 Numbers Test ---\n";
	try
	{
		Span bigSpan(10000);
		std::vector<int> v;
		for (int i = 0; i < 10000; ++i)
			v.push_back(i * 2);
		bigSpan.addRange(v.begin(), v.end());
		std::cout << "Shortest: " << bigSpan.shortestSpan() << '\n';
		std::cout << "Longest: " << bigSpan.longestSpan() << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
