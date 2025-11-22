/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:45 by youbella          #+#    #+#             */
/*   Updated: 2025/11/21 18:59:30 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Cat	cat1;
	Cat	cat2;

	cat1 = cat2;

	cat1.makeSound();
	cat2.makeSound();
}
