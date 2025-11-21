#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource constructor called\n";
    for (int i = 0; i < MAX_MATERIAS; i++)
        _learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
    std::cout << "MateriaSource copy constructor called\n";
    for (int i = 0; i < MAX_MATERIAS; i++)
	{
        if (other._learnedMaterias[i] != NULL)
            _learnedMaterias[i] = other._learnedMaterias[i]->clone();  
        else
            _learnedMaterias[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const & other)
{
    std::cout << "MateriaSource assignment operator called\n";
    if (this != &other)
	{
        for (int i = 0; i < MAX_MATERIAS; i++)
		{
            if (_learnedMaterias[i] != NULL)
			{
                delete _learnedMaterias[i];
                _learnedMaterias[i] = NULL;
            }
        }
        
        
        for (int i = 0; i < MAX_MATERIAS; i++)
		{
            if (other._learnedMaterias[i] != NULL)
                _learnedMaterias[i] = other._learnedMaterias[i]->clone();  
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called\n";
    for (int i = 0; i < MAX_MATERIAS; i++)
	{
        if (_learnedMaterias[i] != NULL)
            delete _learnedMaterias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m == NULL)
	{
        std::cout << "MateriaSource: Cannot learn NULL materia\n";
        return ;
    }

    for (int i = 0; i < MAX_MATERIAS; i++)
	{
        if (_learnedMaterias[i] == NULL)
		{
            _learnedMaterias[i] = m->clone();  
            std::cout << "MateriaSource learned " << m->getType() << " at slot " << i << "\n";
            return ;
        }
    }
    std::cout << "MateriaSource: Cannot learn " << m->getType() << " - memory full!\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < MAX_MATERIAS; i++)
	{
        if (_learnedMaterias[i] != NULL && _learnedMaterias[i]->getType() == type)
		{
            std::cout << "MateriaSource creating " << type << " from slot " << i << "\n";
            return _learnedMaterias[i]->clone();  
        }
    }
    std::cout << "MateriaSource: Unknown materia type '" << type << "'\n";
    return (NULL);  
}
