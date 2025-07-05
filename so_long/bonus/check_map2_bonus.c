/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:41:25 by youbella          #+#    #+#             */
/*   Updated: 2025/04/08 20:24:24 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'Z' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static char	**copy_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	find_player(char **copy)
{
	int	x;
	int	y;

	y = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == 'P')
			{
				flood_fill(copy, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	check_item(char **copy)
{
	int	x;
	int	y;

	y = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == 'C' || copy[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	is_path_valid(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	copy = copy_map(map);
	if (!copy)
		return (0);
	find_player(copy);
	if (check_item(copy))
	{
		while (copy[i])
			free(copy[i++]);
		free(copy);
		ft_putstr_fd("Map path invalid: C or E unreachable\n", 2, NULL);
		return (0);
	}
	while (copy[i])
		free(copy[i++]);
	free(copy);
	return (1);
}
