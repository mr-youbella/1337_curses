#ifndef	CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public	ICharacter
{
private:
	AMateria	*_inventory[4];
	std::string	name;
public:
	Character(void);
	Character(const std::string &name);
	Character(const Character &other);
	Character	&operator=( const Character &other);
	const std::string	&getName(void) const;
	void				equip(AMateria	*m);
	void				unequip(int	idx);
	void				use(int idx, ICharacter	&target);
	virtual	~Character(void);
};


#endif
