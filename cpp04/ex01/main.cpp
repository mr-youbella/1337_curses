/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:45 by youbella          #+#    #+#             */
/*   Updated: 2025/11/20 17:25:45 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Cat	*cat1 = new Cat();
	Cat	*cat2 = new Cat(*cat1);
	Cat	*cat3 = new Cat();
	*cat3 = *cat1;

	delete cat1;
	delete cat2;
	delete cat3;
}
