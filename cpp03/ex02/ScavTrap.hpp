/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:11:10 by youbella          #+#    #+#             */
/*   Updated: 2025/11/16 22:11:12 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap: public	ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &clap_trap);
		ScavTrap	&operator=(const ScavTrap &clap_trap);
		void		attack(const std::string &target);
		void		guardGate();
		~ScavTrap();
};

#endif
