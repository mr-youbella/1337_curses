/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_time_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 02:04:31 by youbella          #+#    #+#             */
/*   Updated: 2025/06/10 20:32:51 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

size_t	time_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	*good_sleep(size_t t_x)
{
	size_t	start;

	start = time_now();
	while ((time_now() - start) < t_x)
		usleep(100);
	return (NULL);
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
