/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:08:56 by youbella          #+#    #+#             */
/*   Updated: 2025/11/24 17:01:04 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// void	f() {system("leaks materia");}

int main()
{
	// atexit(f);
	{
		IMateriaSource* src = new MateriaSource();
		AMateria *m = new Ice();
		src->learnMateria(m);
		delete m;
		m = new Cure();
		src->learnMateria(m);
		delete m;
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	
	std::cout << '\n';

	{	
		AMateria	*ice = new Ice();
		std::cout << ice->getType() << '\n';
	
		AMateria	*ice2 = ice->clone();
		std::cout << ice->getType() << '\n';

		delete ice;
		delete ice2;
	
		// ----------------------------------------------

		MateriaSource	newM;
		Cure			*newCure = new Cure;
		newM.learnMateria(newCure);
		AMateria	*cure = newM.createMateria("cure");
		std::cout << cure->getType() << '\n';
	
		delete newCure;
		delete cure;
	
		// ----------------------------------------------

		Character	youbella("youbella");
		Character	younes("younes");

		std::cout << youbella.getName() << '\n';
		std::cout << younes.getName() << '\n';

		youbella.equip(new Ice);
		youbella.equip(new Cure);
		younes.equip(new Cure);
		younes.equip(new Ice);

		youbella.use(0, younes);
		younes.use(0, youbella);
		youbella.use(1, younes);
		
		younes.unequip(0);
		younes.use(0, younes);
		younes.use(-1, younes);
		younes.use(1, younes);
	}
}
