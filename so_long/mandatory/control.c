/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:39:10 by youbella          #+#    #+#             */
/*   Updated: 2025/04/07 17:16:05 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *data, int fd)
{
	if (data)
	{
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		if (data->map)
			free_map(data->map);
	}
	if (fd == 1)
		exit(0);
	exit (1);
	return (0);
}

static int	check_collision(t_data *data, int new_x, int new_y)
{
	int	grid_y;
	int	grid_x;

	grid_y = new_y / 64;
	grid_x = new_x / 64;
	if (data->xp_count == data->xp_total)
		data->door = data->open_door;
	if (data->map[grid_y][grid_x] == '1')
		return (0);
	else if (data->map[grid_y][grid_x] == 'C')
	{
		data->map[grid_y][grid_x] = '0';
		data->xp_count++;
	}
	else if (data->map[grid_y][grid_x] == 'E')
	{
		if (data->xp_count == data->xp_total)
			ft_putstr_fd("You WIN!\n", 1, data);
		return (0);
	}
	return (1);
}

static int	move_steve(t_data *data, char move, int sign, char pos)
{
	int	move_possible;

	data->pos = pos;
	if (move == 'x')
		move_possible = check_collision(data, \
		data->move_x + sign, data->move_y);
	else
		move_possible = check_collision(data, \
		data->move_x, data->move_y + sign);
	if (move_possible)
	{
		data->move_count++;
		ft_putnbr_fd(data->move_count, 1);
		ft_putchar_fd('\n', 1);
		return (64);
	}
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_exit(data, 1);
	else if (keycode == KEY_A || keycode == KEY_RL)
		data->move_x -= move_steve(data, 'x', -64, 'l');
	else if (keycode == KEY_D || keycode == KEY_RR)
		data->move_x += move_steve(data, 'x', 64, 'r');
	else if (keycode == KEY_W || keycode == KEY_RU)
		data->move_y -= move_steve(data, 'y', -64, 'u');
	else if (keycode == KEY_S || keycode == KEY_RD)
		data->move_y += move_steve(data, 'y', 64, 'd');
	check_collision(data, data->move_x, data->move_y);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data, 0, 0);
	return (1);
}

void	create_game(char **map, int hei)
{
	t_data	data;
	int		wid;

	data.move_x = -1;
	data.move_y = -1;
	data.xp_count = 0;
	data.move_count = 0;
	data.pos = 'd';
	data.xp_total = check_map_elements(map, &wid, &wid, 0);
	data.map = map;
	data.mlx = mlx_init();
	if (!data.mlx)
		(ft_putstr_fd("MLX not init!\n", 2, &data));
	wid = ft_strlen(map[0]);
	hei = 0;
	while (map[hei])
		hei++;
	data.win = mlx_new_window(data.mlx, wid * 64, hei * 64, "Minecraft 2D");
	if (!data.win)
		(ft_putstr_fd("Win not open!\n", 2, &data));
	file_image(&data);
	draw_map(&data, 0, 0);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 17, 1L << 0, ft_exit, &data);
	mlx_loop(data.mlx);
}
