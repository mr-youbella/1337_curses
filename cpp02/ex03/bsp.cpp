/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:02:34 by youbella          #+#    #+#             */
/*   Updated: 2025/11/01 21:21:50 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float area(Point a, Point b, Point c)
{
    return std::abs(
		(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
		 b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
		 c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f
    );
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
    float A = area(a, b, c);
    float A1 = area(point, b, c);
    float A2 = area(a, point, c);
    float A3 = area(a, b, point);

    if (A1 == 0 || A2 == 0 || A3 == 0)
        return false;
    return (A == A1 + A2 + A3);
}
