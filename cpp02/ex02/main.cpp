/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 23:53:07 by youbella          #+#    #+#             */
/*   Updated: 2025/11/10 13:06:54 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a(13);
	Fixed b(a);
	Fixed k(37);
	Fixed c = b;
	Fixed d;

	std::cout << a.toInt() << '\n';
	std::cout << b.toInt() << '\n';

	d = a.min(b, k);
	std::cout << d.toInt() << '\n';
	d = a.max(b, k);
	std::cout << d.toInt() << '\n';
	
	std::cout << (a == b) << '\n';
	std::cout << (a > b) << '\n';

	std::cout << a + b << '\n';

}
