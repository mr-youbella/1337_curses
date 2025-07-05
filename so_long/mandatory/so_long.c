/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:48:20 by youbella          #+#    #+#             */
/*   Updated: 2025/04/08 20:35:51 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_close(char	*join_line, char *line, int fd)
{
	close(fd);
	if (line)
		free(line);
	free(join_line);
}

static char	**ft_read_map(char *path_file, char	*line, char	*join_line)
{
	char	**map;
	int		fd;

	fd = open(path_file, O_RDONLY, 0777);
	if (fd == -1)
		ft_putstr_fd("Error: file not open!\n", 2, NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "\n", 1) == 0)
		{
			free_close(join_line, line, fd);
			ft_putstr_fd("Error: Empty line!\n", 2, NULL);
		}
		join_line = ft_strjoin(join_line, line);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(join_line, '\n');
	if (!map)
	{
		free_close(join_line, NULL, fd);
		ft_putstr_fd("Map no found\n", 2, NULL);
	}
	return (free_close(join_line, NULL, fd), map);
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		ft_putstr_fd("arg != 2\n", 2, NULL);
	else
	{
		if (!ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4))
		{
			map = ft_read_map(argv[1], NULL, NULL);
			check_map(map);
		}
		else
			ft_putstr_fd("Problem name!\n", 2, NULL);
	}
}
