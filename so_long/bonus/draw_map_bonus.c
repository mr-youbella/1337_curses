/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:10:16 by youbella          #+#    #+#             */
/*   Updated: 2025/04/07 16:00:07 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static void	put_check_image(void	*img, t_data *data, int wid, int hei)
{
	if (wid == -13374218)
	{
		if (!data->wall || !data->steve_up || !data->steve_down \
			|| !data->steve_left || !data->steve_right || !data->zombie \
			|| !data->zombie2 || !data->xp || !data->door \
			|| !data->open_door || !data->background)
			ft_putstr_fd("Img not found\n", 2, data);
	}
	else
		mlx_put_image_to_window(data->mlx, data->win, img, wid * 64, hei * 64);
}

void	file_image(t_data *data, int size)
{
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
	data->zombie = mlx_xpm_file_to_image(data->mlx, \
	"img/zombie.xpm", &size, &size);
	data->zombie2 = mlx_xpm_file_to_image(data->mlx, \
	"img/zombie2.xpm", &size, &size);
	data->xp = mlx_xpm_file_to_image(data->mlx, \
	"img/xp.xpm", &size, &size);
	data->door = mlx_xpm_file_to_image(data->mlx, \
	"img/door.xpm", &size, &size);
	data->open_door = mlx_xpm_file_to_image(data->mlx, \
	"img/open_door.xpm", &size, &size);
	data->background = mlx_xpm_file_to_image(data->mlx, \
	"img/background.xpm", &size, &size);
	put_check_image(NULL, data, -13374218, -13374218);
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
		put_check_image(data->background, data, width, height);
	}
	else if (data->map[height][width] == '0')
		put_check_image(data->background, data, width, height);
	else if (data->map[height][width] == '1')
		put_check_image(data->wall, data, width, height);
	else if (data->map[height][width] == 'Z')
	{
		if (data->anim_frame / data->anim_speed % 2 == 0)
			put_check_image(data->zombie, data, width, height);
		else
			put_check_image(data->zombie2, data, width, height);
	}
	else if (data->map[height][width] == 'C')
		put_check_image(data->xp, data, width, height);
	else if (data->map[height][width] == 'E')
		put_check_image(data->door, data, width, height);
	print_moves_score(data);
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
