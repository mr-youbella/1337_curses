/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 02:21:06 by youbella          #+#    #+#             */
/*   Updated: 2026/03/10 18:11:14 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: ARGS != 2.\n";
		return (1);
	}
	BitcoinExchange btc;
	btc.loadDatabase("data.csv");
	btc.processInput(argv[1]);
	return (0);
}
