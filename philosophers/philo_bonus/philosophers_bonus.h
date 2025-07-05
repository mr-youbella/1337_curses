/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:52:02 by youbella          #+#    #+#             */
/*   Updated: 2025/06/19 17:24:38 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# define GREEN "\033[32m"
# define RED "\033[31m"
# define BGRED "\033[41m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define DEF "\033[0m"

typedef struct s_data
{
	sem_t	*forks;
	sem_t	*is_died_sem;
	sem_t	*print_sem;
	sem_t	*eat_mutex;
	size_t	n_philo;
	size_t	t_d;
	size_t	t_e;
	size_t	t_s;
	size_t	number_meals;
	size_t	start_time;
}	t_data;

typedef struct s_philo
{
	size_t	id;
	t_data	*data;
	size_t	last_meal;
	size_t	number_meal_eat;
	pid_t	pid;
}	t_philo;

void	process(t_philo *philo);
short	check_numbers(int argc, char **argv, int i, int j);
short	check_inputs(int argc, char **argv);
size_t	status_print(t_philo *philo, char *status);
size_t	time_now(void);
void	*good_sleep(size_t t_x);
void	sem_end(t_data *data, short close);
void	eating(t_philo *philo);
short	one_philo(t_philo *philo);
ssize_t	ft_atoi(const char *str);

#endif
