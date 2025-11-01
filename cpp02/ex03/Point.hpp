/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:43:36 by youbella          #+#    #+#             */
/*   Updated: 2025/11/01 21:20:29 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(float x, float y);
		Point(const Point &copyPoint);
		Point	&operator=(const Point &copyPoint);
		Fixed	getX();
		Fixed	getY();
		~Point();
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
