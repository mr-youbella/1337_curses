/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:32:32 by youbella          #+#    #+#             */
/*   Updated: 2025/10/22 22:07:05 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z;
	int		N;
	int		i;

	N = 13;
	i = 0;
	z = zombieHorde(N, "zombie");
	while (i < N)
		z[i++].announce();
	delete[] z;
}
