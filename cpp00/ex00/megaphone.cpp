/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:24:34 by youbella          #+#    #+#             */
/*   Updated: 2025/09/03 14:29:31 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc <= 1)
	{
		std::cout << "\033[31m* LOUD AND UNBEARABLE FEEDBACK NOISE *\n\033[0m";
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << (char)toupper(argv[i][j]);
			j++;
		}
		std::cout << ' ';
		i++;
	}
	std::cout << '\n';
	return (0);
}
