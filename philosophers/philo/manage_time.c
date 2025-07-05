/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 02:04:31 by youbella          #+#    #+#             */
/*   Updated: 2025/05/27 18:46:57 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	time_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	*good_sleep(size_t t_x, t_data *data)
{
	size_t	start;

	start = time_now();
	while ((time_now() - start) < t_x)
	{
		if (data)
		{
			pthread_mutex_lock(&data->is_died_mutex);
			if (data->is_died)
			{
				pthread_mutex_unlock(&data->is_died_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&data->is_died_mutex);
		}
		usleep(100);
	}
	return (NULL);
}
