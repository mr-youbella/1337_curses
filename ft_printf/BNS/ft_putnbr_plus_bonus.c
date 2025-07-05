/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_plus_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:25:54 by youbella          #+#    #+#             */
/*   Updated: 2024/12/06 12:07:25 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_plus_bonus(int nb)
{
	int	len;

	len = 0;
	if (nb >= 0)
		len += ft_putchar('+');
	len += ft_putnbr(nb);
	return (len);
}
