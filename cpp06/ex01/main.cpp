/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 08:55:31 by youbella          #+#    #+#             */
/*   Updated: 2026/01/29 17:47:33 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data	d;
	d.str = "hello";
	d.num = 42;

	Data	*p = &d;

	uintptr_t	raw = Serializer::serialize(p);
	Data		*back = Serializer::deserialize(raw);

	std::cout << "p    = " << p << "\n";
	std::cout << "raw  = " << raw << "\n";
	std::cout << "back = " << back << "\n";

	std::cout << "back->s = " << back->str << "\n";
	std::cout << "back->n = " << back->num << "\n";

	std::cout << "same pointer? " << (p == back ? "Yes" : "No") << "\n";
}
