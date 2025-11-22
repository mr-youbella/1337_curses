/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:01:56 by youbella          #+#    #+#             */
/*   Updated: 2025/11/21 18:22:28 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character: public	ICharacter
{
	private:
		AMateria	*inventory[4];
		std::string	name;
	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &other);
		Character			&operator=(const Character &other);
		const std::string	&getName(void) const;
		void				equip(AMateria	*m);
		void				unequip(int	id);
		void				use(int id, ICharacter	&target);
		virtual	~Character(void);
};

#endif
