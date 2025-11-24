/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:22:40 by youbella          #+#    #+#             */
/*   Updated: 2025/11/23 10:33:46 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called\n";
	for (int i = 0; i < MAX_MATERIAS; i++)
		learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	std::cout << "MateriaSource copy constructor called\n";
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (other.learnedMaterias[i] != NULL)
			learnedMaterias[i] = other.learnedMaterias[i]->clone();  
		else
			learnedMaterias[i] = NULL;
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other)
{
	std::cout << "MateriaSource assignment operator called\n";
	if (this != &other)
	{
		for (int i = 0; i < MAX_MATERIAS; i++)
		{
			if (learnedMaterias[i] != NULL)
			{
				delete learnedMaterias[i];
				learnedMaterias[i] = NULL;
			}
		}
		for (int i = 0; i < MAX_MATERIAS; i++)
		{
			if (other.learnedMaterias[i] != NULL)
				learnedMaterias[i] = other.learnedMaterias[i]->clone();  
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << "MateriaSource: Cannot learn NULL materia\n";
		return ;
	}
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (learnedMaterias[i] == NULL)
		{
			learnedMaterias[i] = m->clone();  
			std::cout << "MateriaSource learned " << m->getType() << " at slot " << i << "\n";
			return ;
		}
	}
	std::cout << "MateriaSource: Cannot learn " << m->getType() << " - memory full!\n";
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (learnedMaterias[i] != NULL && learnedMaterias[i]->getType() == type)
		{
			std::cout << "MateriaSource creating " << type << " from slot " << i << "\n";
			return (learnedMaterias[i]->clone());
		}
	}
	std::cout << "MateriaSource: Unknown materia type '" << type << "'\n";
	return (NULL);  
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called\n";
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (learnedMaterias[i] != NULL)
			delete learnedMaterias[i];
	}
}
