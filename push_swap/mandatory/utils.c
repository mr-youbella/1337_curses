/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:21:30 by youbella          #+#    #+#             */
/*   Updated: 2025/04/11 21:21:17 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len)
		p[i++] = s[start++];
	p[i] = 0;
	return (p);
}

void	ft_putstr_fd(char *s, int fd, char **numbers, t_stack **stack_a)
{
	if (fd < 0 || !s)
		return ;
	write(fd, s, ft_strlen(s));
	if (fd == 2)
	{
		if (numbers)
			free_split(numbers);
		if (stack_a)
			ft_lstclear(stack_a);
		exit(1);
	}
}

ssize_t	ft_atoi(const char *str)
{
	size_t	i;
	size_t	result;
	short	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - 48;
	return (result * sign);
}
