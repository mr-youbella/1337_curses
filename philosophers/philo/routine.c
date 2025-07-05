/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 02:01:00 by youbella          #+#    #+#             */
/*   Updated: 2025/06/17 21:49:56 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	died(t_philo *philo, size_t i)
{
	size_t	t_now;

	t_now = time_now();
	pthread_mutex_lock(&philo->data->is_died_mutex);
	philo->data->is_died = 1;
	pthread_mutex_unlock(&philo->data->is_died_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	printf(RED "%lu %lu died\n" DEF,
		t_now - philo->data->start_time, philo[i].id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	status_print(t_philo *philo, char *status, size_t t_now, char *color)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	pthread_mutex_lock(&philo->data->is_died_mutex);
	if (philo->data->is_died)
	{
		pthread_mutex_unlock(&philo->data->is_died_mutex);
		pthread_mutex_unlock(&philo->data->print_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->is_died_mutex);
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
	printf("%s%lu %lu %s\n" DEF,
		color, (t_now - philo->data->start_time), philo->id, status);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal = time_now();
	philo->is_eating = 1;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	status_print(philo, "is eating", 0, NULL);
	good_sleep(philo->data->t_e, philo->data);
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	pthread_mutex_unlock(&philo->data->forks[philo->left]);
	pthread_mutex_unlock(&philo->data->forks[philo->right]);
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->number_meal_eat++;
	pthread_mutex_unlock(&philo->data->meal_mutex);
}

static short	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left]);
	status_print(philo, "has taken a fork", 0, NULL);
	if (philo->data->n_philo == 1)
	{
		good_sleep(philo->data->t_d, NULL);
		pthread_mutex_unlock(&philo->data->forks[philo->left]);
		status_print(philo, "died", 0, NULL);
		return (0);
	}
	pthread_mutex_lock(&philo->data->forks[philo->right]);
	status_print(philo, "has taken a fork", 0, NULL);
	eating(philo);
	pthread_mutex_lock(&philo->data->meal_mutex);
	if (philo->data->number_meals > 0
		&& philo->number_meal_eat == philo->data->number_meals)
	{
		pthread_mutex_unlock(&philo->data->meal_mutex);
		pthread_mutex_lock(&philo->data->eat_mutex);
		philo->data->is_all_eating_count++;
		pthread_mutex_unlock(&philo->data->eat_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->meal_mutex);
	return (1);
}

void	*process(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(1500);
	while (1)
	{
		pthread_mutex_lock(&philo->data->is_fail_mutex);
		if (philo->data->is_fail)
			return (pthread_mutex_unlock(&philo->data->is_fail_mutex), NULL);
		pthread_mutex_unlock(&philo->data->is_fail_mutex);
		pthread_mutex_lock(&philo->data->is_died_mutex);
		if (philo->data->is_died)
			return (pthread_mutex_unlock(&philo->data->is_died_mutex), NULL);
		pthread_mutex_unlock(&philo->data->is_died_mutex);
		if (!take_forks(philo))
			break ;
		status_print(philo, "is sleeping", 0, NULL);
		good_sleep(philo->data->t_s, philo->data);
		status_print(philo, "is thinking", 0, NULL);
	}
	return (NULL);
}
