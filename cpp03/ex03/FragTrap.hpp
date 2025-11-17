/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:29:54 by youbella          #+#    #+#             */
/*   Updated: 2025/11/16 22:29:55 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap: virtual public	ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &frag_trap);
		FragTrap	&operator=(const FragTrap &frag_trap);
		void		attack(const std::string &target);
		void		highFivesGuys(void);
		~FragTrap();
};

#endif
