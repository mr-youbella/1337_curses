/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:28 by youbella          #+#    #+#             */
/*   Updated: 2025/11/21 19:00:15 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class	Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat &other);
		Cat		&operator=(const Cat &other);
		void	makeSound(void) const;
		~Cat(void);
};

#endif
