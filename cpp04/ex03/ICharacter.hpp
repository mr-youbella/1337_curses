#ifndef	ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual	std::string	const	&getName(void) const = 0;
		virtual	void				equip(AMateria	*m) = 0;
		virtual	void				unequip(int	id) = 0;
		virtual	void				use(int id, ICharacter	&target) = 0;
		virtual ~ICharacter() {}
};

#endif
