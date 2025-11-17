/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:23:57 by youbella          #+#    #+#             */
/*   Updated: 2025/11/16 21:48:33 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap: public	FragTrap, public	ScavTrap
{
	private:
		std::string	name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &diamond_trap);
		DiamondTrap	&operator=(const DiamondTrap &diamond_trap);
		void		attack(const std::string &target);
		void		whoAmI(void);
		~DiamondTrap(void);
};

#endif
