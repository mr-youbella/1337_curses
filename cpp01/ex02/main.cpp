/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:03:16 by youbella          #+#    #+#             */
/*   Updated: 2025/10/17 17:34:15 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str;
	std::string	*stringPTR;
	std::string	&stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
	std::cout << "• The memory address of the string    : " << &str << '\n';
	std::cout << "• The memory address held by stringPTR: " << stringPTR << '\n';
	std::cout << "• The memory address held by stringREF: " << &stringREF << '\n';
	std::cout << std::endl;
	std::cout << "• The value of the string          : " << str << '\n';
	std::cout << "• The value pointed to by stringPTR: " << *stringPTR << '\n';
	std::cout << "• The value pointed to by stringREF: " << stringREF << '\n';
}
