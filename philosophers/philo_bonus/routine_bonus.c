/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:35:49 by youbella          #+#    #+#             */
/*   Updated: 2025/06/10 20:31:27 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	status_print(t_philo *philo, char *status)
{
	size_t	t_now;
	char	*color;

	sem_wait(philo->data->print_sem);
	t_now = time_now();
	if (!ft_strncmp(status, "is eating", ft_strlen("is eating")))
		color = GREEN;
	else if (!ft_strncmp(status, "is sleeping", ft_strlen("is sleeping")))
		color = PINK;
	else if (!ft_strncmp(status, "died", ft_strlen("died")))
		color = RED;
	else if (!ft_strncmp(status, "is thinking", ft_strlen("is thinking")))
		color = YELLOW;
	else
		color = BLUE;
	printf("%s%lu %zu %s\n" DEF, \
			color, (t_now - philo->data->start_time), philo->id, status);
	if (ft_strncmp(status, "died", ft_strlen("died")))
		sem_post(philo->data->print_sem);
	return (t_now);
}

static void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		usleep(500);
		if (time_now() - philo->last_meal >= philo->data->t_d)
		{
			sem_wait(philo->data->is_died_sem);
			status_print(philo, "died");
			exit(1);
		}
	}
	return (NULL);
}

void	process(t_philo *philo)
{
	pthread_t	mon;

	if (!pthread_create(&mon, NULL, monitor, philo))
		pthread_detach(mon);
	else
		exit(1);
	if (philo->id % 2 == 0)
		usleep(1500);
	while (1)
	{
		sem_wait(philo->data->forks);
		status_print(philo, "has taken a fork");
		if (!one_philo(philo))
			exit(1);
		sem_wait(philo->data->forks);
		status_print(philo, "has taken a fork");
		eating(philo);
		philo->number_meal_eat++;
		if (philo->data->number_meals > 0 && \
			philo->number_meal_eat >= philo->data->number_meals)
			exit(0);
		status_print(philo, "is sleeping");
		good_sleep(philo->data->t_s);
		status_print(philo, "is thinking");
	}
}
