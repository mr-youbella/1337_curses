/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:25:33 by youbella          #+#    #+#             */
/*   Updated: 2024/12/06 12:25:36 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_add(unsigned long nb);
int	ft_putnbr(int nb);
int	ft_putnbr_un(unsigned int nb);
int	ft_putnbr_hex(unsigned int nb, char x);
int	ft_putnbr_hash_bonus(unsigned int nb, char x);
int	ft_putnbr_space_bonus(int nb);
int	ft_putnbr_plus_bonus(int nb);

#endif
