/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:55:01 by youbella          #+#    #+#             */
/*   Updated: 2025/06/16 17:08:50 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

short	check_died(t_philo *philo, size_t i)
{
	pthread_mutex_lock(&philo->data->meal_mutex);
	if (!philo[i].is_eating
		&& time_now() - philo[i].last_meal >= philo->data->t_d)
	{
		if (!(philo->data->number_meals
				&& philo[i].number_meal_eat == philo->data->number_meals))
			died(philo, i);
		return (pthread_mutex_unlock(&philo->data->meal_mutex), 0);
	}
	pthread_mutex_unlock(&philo->data->meal_mutex);
	return (1);
}

void	detach(t_data *data, pthread_t *th, size_t i)
{
	size_t		j;

	j = 0;
	pthread_mutex_lock(&data->is_fail_mutex);
	data->is_fail = 1;
	pthread_mutex_unlock(&data->is_fail_mutex);
	while (j < i)
	{
		pthread_join(th[j], NULL);
		j++;
	}
}

short	des(t_data *data, size_t i, short destroy, size_t j)
{
	if (destroy == 1)
		return (pthread_mutex_destroy(&data->eat_mutex), 0);
	if (destroy == 2)
	{
		pthread_mutex_destroy(&data->eat_mutex);
		return (pthread_mutex_destroy(&data->print_mutex), 0);
	}
	if (destroy == 3)
	{
		pthread_mutex_destroy(&data->eat_mutex);
		pthread_mutex_destroy(&data->print_mutex);
		return (pthread_mutex_destroy(&data->meal_mutex), 0);
	}
	if (destroy == 4)
	{
		pthread_mutex_destroy(&data->eat_mutex);
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(&data->is_died_mutex);
		return (pthread_mutex_destroy(&data->meal_mutex), 0);
	}
	while (j < i)
		pthread_mutex_destroy(&data->forks[j++]);
	return (0);
}

short	init_mutex(t_data *data)
{
	size_t	i;

	i = 0;
	if (pthread_mutex_init(&data->eat_mutex, NULL))
		return (printf(BGRED "Didn't init mutex\n" DEF), 0);
	if (pthread_mutex_init(&data->print_mutex, NULL))
		return (des(data, i, 1, 0), printf(BGRED "Didn't init mutex\n" DEF), 0);
	if (pthread_mutex_init(&data->meal_mutex, NULL))
		return (des(data, i, 2, 0), printf(BGRED "Didn't init mutex\n" DEF), 0);
	if (pthread_mutex_init(&data->is_died_mutex, NULL))
		return (des(data, i, 3, 0), printf(BGRED "Didn't init mutex\n" DEF), 0);
	if (pthread_mutex_init(&data->is_fail_mutex, NULL))
		return (des(data, i, 4, 0), printf(BGRED "Didn't init mutex\n" DEF), 0);
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
		{
			printf(BGRED "Didn't init mutex\n" DEF);
			des(data, i, -1, 0);
			return (0);
		}
		i++;
	}
	return (1);
}

void	init_var(int argc, char **argv, t_philo *philo, t_data *data)
{
	size_t	i;

	i = 0;
	data->n_philo = ft_atoi(argv[1]);
	data->t_d = ft_atoi(argv[2]);
	data->t_e = ft_atoi(argv[3]);
	data->t_s = ft_atoi(argv[4]);
	data->start_time = time_now();
	data->is_all_eating_count = 0;
	(1) && (data->is_died = 0, data->is_fail = 0);
	if (argc == 6)
		data->number_meals = ft_atoi(argv[5]);
	else
		data->number_meals = 0;
	while (i < data->n_philo)
	{
		philo[i].data = data;
		philo[i].id = i + 1;
		philo[i].left = i;
		philo[i].right = (i + 1) % data->n_philo;
		philo[i].last_meal = data->start_time;
		philo[i].number_meal_eat = 0;
		philo[i].is_eating = 0;
		i++;
	}
}
