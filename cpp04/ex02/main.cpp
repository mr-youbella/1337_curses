/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:45 by youbella          #+#    #+#             */
/*   Updated: 2025/11/24 16:51:56 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

// void	f() {system("leaks brain");}

int main(void)
{
	// atexit(f);
	{
		const int	size = 4;
		Animal		*animals[size];

		for (int i = 0; i < size / 2; i++)
			animals[i] = new Dog();

		for (int i = size / 2; i < size; i++)
			animals[i] = new Cat();

		for (int i = 0; i < size; i++)
			delete animals[i];
	}
	std::cout << '\n';
	{
		// Animal base;
		Cat	*cat = new Cat;	
		Cat	*cat1 = new Cat;

		*cat1 = *cat;
		delete cat;
		delete cat1;
	}
}
