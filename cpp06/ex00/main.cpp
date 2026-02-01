/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 08:55:31 by youbella          #+#    #+#             */
/*   Updated: 2026/01/31 14:28:24 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Please Enter one literal.\n", 1);
	ScalarConverter::convert(argv[1]);
	return (0);
}
