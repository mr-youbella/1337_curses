/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:53:04 by youbella          #+#    #+#             */
/*   Updated: 2025/11/20 16:42:20 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class	ICharacter;

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria(void);
		AMateria(const std::string &type);
		AMateria(const AMateria &other);
		AMateria	&operator=(const AMateria &other);
		std::string const &getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
		virtual ~AMateria(void);
};

#endif
