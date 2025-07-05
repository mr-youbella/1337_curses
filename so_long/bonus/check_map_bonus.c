/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:57:47 by youbella          #+#    #+#             */
/*   Updated: 2025/04/08 20:22:32 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_map_elements_z(char **map)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	z = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'Z')
				z++;
			j++;
		}
		i++;
	}
	if (z < 1)
		ft_putstr_fd("Must 1(P) 1(E) >1(C,Z)\n", 2, NULL);
	return (z);
}

int	check_map_elements(char **map, int *e, int *p, int c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != '0' && \
				map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != 'Z')
				return (ft_putstr_fd("just (01PECZ)\n", 2, NULL), 0);
			if (map[i][j] == 'P')
				(*p)++;
			else if (map[i][j] == 'E')
				(*e)++;
			else if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

static int	check_map_struct(char **map)
{
	int	i;
	int	width;
	int	len;

	i = 0;
	width = ft_strlen(map[0]);
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len != width)
			return (ft_putstr_fd("Unbalanced structure.\n", 2, NULL), 0);
		i++;
	}
	return (1);
}

static int	check_map_border(char **map)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	height = 0;
	width = ft_strlen(map[0]);
	while (map[height] != NULL)
		height++;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (ft_putstr_fd("ERROR: Border is not closed!\n", 2, NULL), 0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (ft_putstr_fd("ERROR: Border is not closed!\n", 2, NULL), 0);
		i++;
	}
	return (1);
}

char	**check_map(char **map)
{
	int	count_e;
	int	count_p;
	int	count_c;

	count_e = 0;
	count_p = 0;
	count_c = 0;
	check_map_struct(map);
	check_map_border(map);
	count_c = check_map_elements(map, &count_e, &count_p, count_c);
	if (count_c < 1 || count_p != 1 || count_e != 1)
		ft_putstr_fd("Must 1(P) 1(E) >1(C)\n", 2, NULL);
	check_map_elements_z(map);
	is_path_valid(map);
	is_path_valid_2(map);
	create_game(map, 0);
	return (map);
}
