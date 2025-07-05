/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:58:38 by youbella          #+#    #+#             */
/*   Updated: 2025/03/30 00:48:17 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_digit(int n)
{
	int	d;

	d = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		d++;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*p;

	digit = ft_digit(n);
	if (n < 0)
		digit++;
	p = malloc(digit + 1);
	p[digit] = 0;
	if (!p)
		return (NULL);
	if (n < 0)
	{
		p[0] = '-';
		n *= -1;
	}
	digit--;
	while (digit >= 0)
	{
		if (p[digit] == '-')
			break ;
		p[digit--] = (n % 10) + 48;
		n /= 10;
	}
	return (p);
}
