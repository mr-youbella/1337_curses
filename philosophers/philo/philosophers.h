/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:57:30 by youbella          #+#    #+#             */
/*   Updated: 2025/06/11 17:01:25 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

# define GREEN "\033[32m"
# define RED "\033[31m"
# define BGRED "\033[41m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define DEF "\033[0m"

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	is_died_mutex;
	pthread_mutex_t	is_fail_mutex;
	size_t			start_time;
	size_t			n_philo;
	size_t			t_d;
	size_t			t_e;
	size_t			t_s;
	size_t			number_meals;
	size_t			is_all_eating_count;
	size_t			is_died;
	size_t			is_fail;
}	t_data;

typedef struct s_philo
{
	size_t	id;
	size_t	left;
	size_t	right;
	size_t	number_meal_eat;
	size_t	last_meal;
	size_t	is_eating;
	t_data	*data;
}	t_philo;

void	*process(void *ptr);
void	status_print(t_philo *philo, char *status, size_t t_now, char *color);
void	*good_sleep(size_t t_x, t_data *data);
size_t	time_now(void);
short	init_mutex(t_data *data);
void	init_var(int argc, char **argv, t_philo *philo, t_data *data);
void	died(t_philo *philo, size_t i);
void	no_leaks(t_philo *philo, t_data *data);
void	detach(t_data *data, pthread_t *th, size_t i);
short	check_died(t_philo *philo, size_t i);
void	*monitor(void *ptr);
ssize_t	ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

#endif
