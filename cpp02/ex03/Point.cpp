/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:43:00 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/16 10:43:00 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &rhs) : _x(rhs._x), _y(rhs._y)
{
}

Point::~Point()
{
}

Point&	Point::operator=(const Point& rhs)
{
	if (this != &rhs)
	{
		(Fixed)_x = rhs.getX();
		(Fixed)_y = rhs.getY();
	}

	return *this;
}

Fixed	Point::getX() const
{
	return this->_x;
}

Fixed	Point::getY() const
{
	return this->_y;
}
