/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:45:46 by youbella          #+#    #+#             */
/*   Updated: 2025/11/10 14:14:54 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0)
{
	std::cout << "Default constructor called\n";
}

Point::Point(float x, float y): x(x), y(y)
{}

Point::Point(const Point &copyPoint) : x(copyPoint.x), y(copyPoint.y)
{
	std::cout << "Copy constructor called\n";
}

Point &Point::operator=(const Point &copyPoint)
{
	std::cout << "Copy assignment operator called\n";
	(void)copyPoint;
	return (*this);
}

Fixed	Point::getX() const
{
	return (x);
}
Fixed	Point::getY() const
{
	return (y);
}

Point::~Point()
{
	std::cout << "Destructor called\n";
}
