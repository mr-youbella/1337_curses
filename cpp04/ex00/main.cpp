/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:45 by youbella          #+#    #+#             */
/*   Updated: 2025/11/24 15:37:34 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
		delete j;
	}
	std::cout << '\n';
	{
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();
	
		std::cout << i->getType() << " " << std::endl;
	
		i->makeSound();
		meta->makeSound();
	
		delete meta;
		delete i;
	}
}
