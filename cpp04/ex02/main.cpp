/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:45 by youbella          #+#    #+#             */
/*   Updated: 2025/11/20 17:34:32 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    // Animal *animal = new Animal();
	Animal *dog = new Dog();
	Animal *cat = new Cat();

	dog->makeSound();  
	cat->makeSound(); 
	delete dog;
	delete cat;
}
