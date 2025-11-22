/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:23 by youbella          #+#    #+#             */
/*   Updated: 2025/11/22 21:14:04 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(const Animal &other);
		Animal			&operator=(const Animal &other);
		std::string		getType(void) const;
		virtual void	makeSound(void) const;
		virtual ~Animal(void);
};

#endif
