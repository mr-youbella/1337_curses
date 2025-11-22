/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:17:15 by youbella          #+#    #+#             */
/*   Updated: 2025/11/21 18:16:57 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &other);
		Ice			&operator=(const Ice &other);
		AMateria	*clone(void) const;
		void		use(ICharacter &target);
		~Ice();
};

#endif
