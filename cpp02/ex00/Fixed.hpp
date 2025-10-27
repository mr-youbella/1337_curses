/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 23:38:25 by youbella          #+#    #+#             */
/*   Updated: 2025/10/18 18:03:24 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	bit;
	public:
		Fixed(void);
		Fixed(const Fixed &copyFixed);
		Fixed	&operator=(const Fixed &copyFixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		~Fixed(void);
};

#endif
