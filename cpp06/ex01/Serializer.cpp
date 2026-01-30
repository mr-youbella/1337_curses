/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:12:03 by youbella          #+#    #+#             */
/*   Updated: 2026/01/30 09:20:34 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default constructor called\n";
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << "Copy constructor called\n";
}

Serializer	&Serializer::operator=(const Serializer &other)
{
	std::cout << "Copy assignment operator called\n";
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

Serializer::~Serializer()
{
	std::cout << "Destructor called\n";
}
