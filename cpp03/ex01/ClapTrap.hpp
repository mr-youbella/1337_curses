/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:08:43 by youbella          #+#    #+#             */
/*   Updated: 2025/11/14 19:12:21 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clap_trap);
		ClapTrap	&operator=(const ClapTrap &clap_trap);
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		~ClapTrap();
};

#endif
