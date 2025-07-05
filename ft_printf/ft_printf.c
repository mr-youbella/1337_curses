/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:25:06 by youbella          #+#    #+#             */
/*   Updated: 2024/12/06 12:07:32 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mandatory(va_list lst, const char *str, size_t *i, short check);

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	size_t	i;
	int		len;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(lst, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += mandatory(lst, str, &i, 0);
		}
		else
			len += ft_putchar(str[i]);
		if (str[i])
			i++;
	}
	va_end(lst);
	return (len);
}

int	mandatory(va_list lst, const char *str, size_t *i, short check)
{
	int	len;

	len = 0;
	if (str[*i + 1] == 'c')
		len += ft_putchar(va_arg(lst, int));
	else if (str[*i + 1] == 's')
		len += ft_putstr(va_arg(lst, char *));
	else if (str[*i + 1] == 'p')
		len += ft_putnbr_add(va_arg(lst, unsigned long));
	else if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
		len += ft_putnbr(va_arg(lst, int));
	else if (str[*i + 1] == 'u')
		len += ft_putnbr_un(va_arg(lst, unsigned int));
	else if (str[*i + 1] == 'x' || str[*i + 1] == 'X')
		len += ft_putnbr_hex(va_arg(lst, unsigned int), str[*i + 1]);
	else if (str[*i + 1] == '%')
		len += ft_putchar('%');
	else if (str[*i + 1])
		len += ft_putchar(str[*i + 1]);
	if (!check)
		*i += 1;
	return (len);
}
