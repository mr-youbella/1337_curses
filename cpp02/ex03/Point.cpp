/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:45:46 by youbella          #+#    #+#             */
/*   Updated: 2025/11/01 21:49:31 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0)
{
	return ;
}

Point::Point(float x, float y): x(x), y(y)
{
	return ;
}

Point::Point(const Point &copyPoint) : x(copyPoint.x), y(copyPoint.y)
{
	return ;
}

Point &Point::operator=(const Point &copyPoint)
{
	(void)copyPoint;
	return (*this);
}

Fixed	Point::getX()
{
	return (x);
}
Fixed	Point::getY()
{
	return (y);
}

Point::~Point()
{
	return ;
}
