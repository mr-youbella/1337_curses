/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:21:54 by youbella          #+#    #+#             */
/*   Updated: 2025/02/27 05:29:26 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

static short	overflow(size_t result, size_t b_result)
{
	if ((result / 10 != b_result) || (result >= LONG_MAX))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		result;
	int		b_result;

	i = 0;
	result = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		b_result = result;
		result = result * 10 + str[i++] - 48;
		if (overflow(result, b_result) == 0)
			return (0);
	}
	if (str[i])
		return (0);
	return (result);
}
