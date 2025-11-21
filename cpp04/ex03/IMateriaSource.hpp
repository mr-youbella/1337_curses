/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:37:31 by youbella          #+#    #+#             */
/*   Updated: 2025/11/20 16:38:23 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"
# include <iostream>

class IMateriaSource
{
	public:
	    virtual ~IMateriaSource() {}
	    virtual void learnMateria(AMateria*) = 0;
	    virtual AMateria* createMateria(const std::string &type) = 0;
};

#endif
