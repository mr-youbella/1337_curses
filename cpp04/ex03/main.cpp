/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:38:39 by youbella          #+#    #+#             */
/*   Updated: 2025/11/20 16:39:02 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Complete Materia System Test ===\n\n";
    
    std::cout << "--- Creating MateriaSource ---\n";
    IMateriaSource* src = new MateriaSource();
    
    std::cout << "\n--- Learning Materias ---\n";
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    
    std::cout << "\n--- Creating Character ---\n";
    ICharacter* me = new Character("me");
    
    std::cout << "\n--- Creating and Equipping Materias ---\n";
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    tmp = src->createMateria("fire");
    if (tmp == NULL) {
        std::cout << "Failed to create unknown materia type\n";
    }
    
    std::cout << "\n--- Creating Target ---\n";
    ICharacter* bob = new Character("bob");
    
    std::cout << "\n--- Using Materias ---\n";
    me->use(0, *bob);
    me->use(1, *bob);
    
    std::cout << "\n--- Testing Copy ---\n";
    MateriaSource src2 = *dynamic_cast<MateriaSource*>(src);
    AMateria* ice2 = src2.createMateria("ice");
    if (ice2 != NULL) {
        std::cout << "Successfully created ice from copied source\n";
        delete ice2;
    }
    
    std::cout << "\n--- Cleaning Up ---\n";
    delete bob;
    delete me;
    delete src;
    
    return 0;
}
