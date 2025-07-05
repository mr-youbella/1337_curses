/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:35:51 by youbella          #+#    #+#             */
/*   Updated: 2025/06/17 21:42:00 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor(void *ptr)
{
	t_philo	*philo;
	size_t	i;

	philo = (t_philo *)ptr;
	while (philo->data->n_philo != 1)
	{
		(1) && (i = 0, usleep(500));
		while (i < philo->data->n_philo)
		{
			pthread_mutex_lock(&philo->data->eat_mutex);
			if (philo->data->is_all_eating_count == philo->data->n_philo)
				return (pthread_mutex_unlock(&philo->data->eat_mutex), NULL);
			pthread_mutex_unlock(&philo->data->eat_mutex);
			if (!check_died(philo, i))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}

static short	thread_create(t_philo *philo, t_data *data, size_t i, size_t j)
{
	pthread_t	*th;
	pthread_t	monitor_thread;

	th = malloc(sizeof(pthread_t) * data->n_philo);
	if (!th)
		return (printf("Error in allocation (pthread_t)"), 0);
	while (i < data->n_philo)
	{
		if (pthread_create(&th[i], NULL, process, &philo[i]))
			break ;
		i++;
	}
	if (i != data->n_philo)
		return (detach(data, th, i), printf(BGRED "FAIL\n" DEF), free(th), 0);
	if (pthread_create(&monitor_thread, NULL, monitor, philo))
	{
		pthread_mutex_lock(&data->is_fail_mutex);
		data->is_fail = 1;
		pthread_mutex_unlock(&data->is_fail_mutex);
	}
	else
		pthread_join(monitor_thread, NULL);
	while (j < data->n_philo)
		pthread_join(th[j++], NULL);
	return (free(th), 1);
}

static short	check_inputs(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[1]) > 200)
		return (printf(BGRED "Use just 1 -> 200 philo.\n" DEF), 0);
	if (!ft_atoi(argv[1]))
		return (2);
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (printf(BGRED "Use just 60 -> LONG_MAX ms.\n" DEF), 0);
	if (argc == 6 && ft_atoi(argv[5]) < 0)
		return (printf(BGRED "Do not use with more than LONG_MAX.\n" DEF), 0);
	if (argc == 6 && !ft_atoi(argv[5]))
		return (2);
	return (1);
}

static short	check_numbers(int argc, char **argv, int i, int j)
{
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+')
			j++;
		if (!argv[i][j])
			return (printf(BGRED "Please Enter just numbers and sign plus.\n"
					DEF), 0);
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (printf(BGRED"Please Enter just numbers and sign plus.\n"
						DEF), 0);
			j++;
		}
		i++;
	}
	if (!check_inputs(argc, argv))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_philo		*philo;

	if (argc != 5 && argc != 6)
		return (printf(BGRED "Pleas Enter number_of_philo t_die t_eat t_sleep \
[number_of_times_each_philosopher_must_eat]\n" DEF), 1);
	if (!check_numbers(argc, argv, 1, 0))
		return (1);
	if (check_inputs(argc, argv) == 2)
		return (0);
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!philo)
		return (printf(BGRED "Error in allocation (t_philo)" DEF), 1);
	init_var(argc, argv, philo, &data);
	data.forks = malloc(sizeof(pthread_mutex_t) * data.n_philo);
	if (!data.forks)
		return (printf(BGRED "Error in allocation (fork)" DEF), free(philo), 1);
	if (!init_mutex(&data))
		return (free(philo), free(data.forks), 1);
	if (!thread_create(philo, &data, 0, 0))
		return (no_leaks(philo, &data), 1);
	no_leaks(philo, &data);
	return (0);
}
