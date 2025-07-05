/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:10:16 by youbella          #+#    #+#             */
/*   Updated: 2025/04/07 15:56:58 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**free_map(char **arr)
{
	size_t	j;

	if (!arr)
		return (NULL);
	j = 0;
	while (arr[j])
	{
		free (arr[j]);
		j++;
	}
	free(arr);
	return (NULL);
}

void	file_image(t_data *data)
{
	int	size;

	size = 64;
	data->wall = mlx_xpm_file_to_image(data->mlx, \
	"img/wall.xpm", &size, &size);
	data->steve_up = mlx_xpm_file_to_image(data->mlx, \
	"img/steve_up.xpm", &size, &size);
	data->steve_down = mlx_xpm_file_to_image(data->mlx, \
	"img/steve_down.xpm", &size, &size);
	data->steve_left = mlx_xpm_file_to_image(data->mlx, \
	"img/steve_left.xpm", &size, &size);
	data->steve_right = mlx_xpm_file_to_image(data->mlx, \
	"img/steve_right.xpm", &size, &size);
	data->xp = mlx_xpm_file_to_image(data->mlx, \
	"img/xp.xpm", &size, &size);
	data->door = mlx_xpm_file_to_image(data->mlx, \
	"img/door.xpm", &size, &size);
	data->open_door = mlx_xpm_file_to_image(data->mlx, \
	"img/open_door.xpm", &size, &size);
	data->background = mlx_xpm_file_to_image(data->mlx, \
	"img/background.xpm", &size, &size);
	if (!data->wall || !data->steve_up || !data->steve_down \
		|| !data->steve_left || !data->steve_right || !data->xp || \
		!data->door || !data->open_door || !data->background)
		ft_putstr_fd("Img not found\n", 2, data);
}

static void	put_image(void	*img, t_data *data, int width, int height)
{
	mlx_put_image_to_window(data->mlx, data->win, img, width * 64, height * 64);
}

static void	put_image_to_map(t_data *data, int width, int height)
{
	if (data->map[height][width] == 'P')
	{
		if (data->move_x == -1 && data->move_y == -1)
		{
			data->move_x = width * 64;
			data->move_y = height * 64;
		}
		put_image(data->background, data, width, height);
	}
	else if (data->map[height][width] == '0')
		put_image(data->background, data, width, height);
	else if (data->map[height][width] == '1')
		put_image(data->wall, data, width, height);
	else if (data->map[height][width] == 'C')
		put_image(data->xp, data, width, height);
	else if (data->map[height][width] == 'E')
		put_image(data->door, data, width, height);
}

void	draw_map(t_data *data, int width, int height)
{
	width = 0;
	height = 0;
	while (data->map[height] != NULL)
	{
		width = 0;
		while (data->map[height][width] != '\0')
		{
			put_image_to_map(data, width, height);
			width++;
		}
		height++;
	}
	if (data->pos == 'l')
		mlx_put_image_to_window(data->mlx, data->win, \
								data->steve_left, data->move_x, data->move_y);
	else if (data->pos == 'r')
		mlx_put_image_to_window(data->mlx, data->win, \
								data->steve_right, data->move_x, data->move_y);
	else if (data->pos == 'u')
		mlx_put_image_to_window(data->mlx, data->win, \
								data->steve_up, data->move_x, data->move_y);
	else if (data->pos == 'd')
		mlx_put_image_to_window(data->mlx, data->win, \
								data->steve_down, data->move_x, data->move_y);
}
