/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 23:38:25 by youbella          #+#    #+#             */
/*   Updated: 2025/10/18 18:30:10 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <ostream>
# include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	bit;
	public:
		Fixed();
		Fixed(int value);
		Fixed(float value);
		Fixed(const Fixed &copyFixed);
		Fixed	&operator=(const Fixed &copyFixed);
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		~Fixed();
};

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed);

#endif
