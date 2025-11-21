/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:48 by youbella          #+#    #+#             */
/*   Updated: 2025/11/20 17:50:21 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal
{
	private:
		Brain	*brain;
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog	&operator=(const Dog &other);
		void	makeSound(void) const;
		~Dog(void);
};

#endif
