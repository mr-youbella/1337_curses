/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:32:47 by youbella          #+#    #+#             */
/*   Updated: 2025/10/16 18:46:59 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*z;
	int		i;

	z = new Zombie[N];
	i = 0;
	while (i < N)
	{
		z[i].ft_name(name);
		i++;
	}
	return (z);
}
