/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:37:31 by youbella          #+#    #+#             */
/*   Updated: 2025/11/23 10:12:15 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual void		learnMateria(AMateria *) = 0;
		virtual AMateria	*createMateria(const std::string &type) = 0;
		virtual ~IMateriaSource() {}
};

#endif
