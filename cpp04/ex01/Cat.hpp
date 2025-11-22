/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:28 by youbella          #+#    #+#             */
/*   Updated: 2025/11/22 21:14:49 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal
{
	private:
		Brain	*brain;
	public:
		Cat(void);
		Cat(const Cat &other);
		Cat		&operator=(const Cat &other);
		void	makeSound(void) const;
		~Cat(void);
};

#endif
