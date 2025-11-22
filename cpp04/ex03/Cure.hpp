/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:16:55 by youbella          #+#    #+#             */
/*   Updated: 2025/11/21 18:16:53 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &other);
		Cure		&operator=(const Cure &other);
		AMateria	*clone(void) const;
		void		use(ICharacter &target);
		~Cure(void);
};

#endif
