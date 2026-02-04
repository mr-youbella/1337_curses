/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 08:22:13 by youbella          #+#    #+#             */
/*   Updated: 2026/02/02 08:28:38 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << '\n';
	std::cout << "min( a, b ) = " << ::min(a, b) << '\n';
	std::cout << "max( a, b ) = " << ::max(a, b) << '\n';

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << '\n';
	std::cout << "min( c, d ) = " << ::min(c, d) << '\n';
	std::cout << "max( c, d ) = " << ::max(c, d) << '\n';

	float e = 13.37;
	float f = 42.42;

	::swap(e, f);
	std::cout << "a = " << e << ", b = " << f << '\n';
	std::cout << "min( a, b ) = " << ::min(e, f) << '\n';
	std::cout << "max( a, b ) = " << ::max(e, f) << '\n';

	return (0);
}
