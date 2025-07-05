/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 23:19:20 by youbella          #+#    #+#             */
/*   Updated: 2025/04/07 17:15:07 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*s)
	{
		s++;
		l++;
	}
	return (l);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd, t_data *data)
{
	if (fd < 0 || !s)
		return ;
	write(fd, s, ft_strlen(s));
	if (data)
	{
		if (data->background)
			mlx_destroy_image(data->mlx, data->background);
		if (data->wall)
			mlx_destroy_image(data->mlx, data->wall);
		if (data->steve_up)
			mlx_destroy_image(data->mlx, data->steve_up);
		if (data->steve_down)
			mlx_destroy_image(data->mlx, data->steve_down);
		if (data->steve_left)
			mlx_destroy_image(data->mlx, data->steve_left);
		if (data->steve_right)
			mlx_destroy_image(data->mlx, data->steve_right);
		if (data->xp)
			mlx_destroy_image(data->mlx, data->xp);
		if (data->door)
			mlx_destroy_image(data->mlx, data->door);
		if (data->open_door && data->open_door != data->door)
			mlx_destroy_image(data->mlx, data->open_door);
	}
	ft_exit(data, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	if (fd < 0)
		return ;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nb <= 9)
		ft_putchar_fd(nb + 48, fd);
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((unsigned char *)b)[i++] = (unsigned char)c;
	return (b);
}
