/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:23 by youbella          #+#    #+#             */
/*   Updated: 2025/11/22 21:14:20 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class	Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain(void);
		Brain(const Brain &other);
		Brain	&operator=(const Brain &other);
		virtual ~Brain(void);
};

#endif
