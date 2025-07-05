/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:02:20 by youbella          #+#    #+#             */
/*   Updated: 2025/06/10 17:58:44 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	no_leaks(t_philo *philo, t_data *data)
{
	size_t	i;

	i = 0;
	pthread_mutex_destroy(&data->eat_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->is_died_mutex);
	pthread_mutex_destroy(&data->is_fail_mutex);
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(philo);
	free(data->forks);
}

static short	overflow(size_t result, size_t b_result)
{
	if ((result / 10 != b_result) || (result > LONG_MAX))
		return (0);
	return (1);
}

ssize_t	ft_atoi(const char *str)
{
	size_t	i;
	size_t	result;
	size_t	before_result;

	i = 0;
	result = 0;
	before_result = 0;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		before_result = result;
		result = result * 10 + str[i] - 48;
		if (!overflow(result, before_result))
			return (-1);
		i++;
	}
	return (result);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
