/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_space_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:21:26 by youbella          #+#    #+#             */
/*   Updated: 2024/12/06 12:07:22 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_space_bonus(int nb)
{
	int	len;

	len = 0;
	if (nb >= 0)
		len += ft_putchar(32);
	len += ft_putnbr(nb);
	return (len);
}
