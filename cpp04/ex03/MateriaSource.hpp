/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:34:12 by youbella          #+#    #+#             */
/*   Updated: 2025/11/20 16:35:53 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _learnedMaterias[4];
		static const int MAX_MATERIAS = 4;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource	&operator=(const MateriaSource &other);
		void 			learnMateria(AMateria* m);
		AMateria		*createMateria(const std::string &type);
		virtual			~MateriaSource();
};

#endif
