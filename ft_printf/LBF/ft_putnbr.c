/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:55:30 by youbella          #+#    #+#             */
/*   Updated: 2024/12/06 12:24:05 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int nb)
{
	int		len;
	long	n;

	len = 0;
	n = nb;
	if (n < 0)
	{
		n *= -1;
		len += ft_putchar('-');
	}
	if (n <= 9)
		len += ft_putchar(n + 48);
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	return (len);
}
