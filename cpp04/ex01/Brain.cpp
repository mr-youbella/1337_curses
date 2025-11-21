/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:21 by youbella          #+#    #+#             */
/*   Updated: 2025/11/20 17:01:27 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Constructor Brain called\n";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Lion";
}

Brain::Brain(const Brain &other)
{
	std::cout << "Copy constructor Brain called\n";
	*this = other;
}

Brain		&Brain::operator=(const Brain &other)
{
	std::cout << "Copy assignment operator Brain called\n";
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Destructor Brain called\n";
}
