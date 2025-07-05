/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:43:00 by youbella          #+#    #+#             */
/*   Updated: 2025/04/08 19:53:47 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_RL 123
# define KEY_RR 124	
# define KEY_RU 126
# define KEY_RD 125

typedef struct data
{
	void	*mlx;
	void	*win;
	void	*background;
	void	*wall;
	void	*steve_up;
	void	*steve_down;
	void	*steve_left;
	void	*steve_right;
	void	*xp;
	void	*door;
	void	*open_door;
	int		move_x;
	int		move_y;
	char	**map;
	int		xp_count;
	int		move_count;
	int		xp_total;
	char	pos;
}	t_data;

void	ft_putstr_fd(char *s, int fd, t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	**check_map(char **map);
void	**free_map(char **arr);
void	create_game(char **map, int hei);
int		ft_exit(t_data *data, int fd);
int		key_press(int keycode, t_data *data);
void	draw_map(t_data *data, int width, int height);
void	file_image(t_data *data);
int		check_map_elements(char **map, int *e, int *p, int c);
int		is_path_valid(char **map);
int		is_path_valid_2(char **map);

#endif
