/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hash_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:44:21 by youbella          #+#    #+#             */
/*   Updated: 2024/12/06 12:24:26 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_hash_bonus(unsigned int nb, char x)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (ft_putchar(48));
	if (x == 'x')
		len += ft_putstr("0x");
	else
		len += ft_putstr("0X");
	len += ft_putnbr_hex(nb, x);
	return (len);
}
