/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:55:30 by youbella          #+#    #+#             */
/*   Updated: 2024/12/06 12:08:14 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_un(unsigned int nb)
{
	int		len;

	len = 0;
	if (nb <= 9)
		len += ft_putchar(nb + 48);
	if (nb > 9)
	{
		len += ft_putnbr_un(nb / 10);
		len += ft_putnbr_un(nb % 10);
	}
	return (len);
}
