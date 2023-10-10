/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:55:20 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/10 15:08:47 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// a, b, c: The vertices of our beloved triangle.
// point: The point to check.
// Returns: True if the point is inside the triangle. False otherwise.
// Thus, if the point is a vertex or on edge, it will return False.
// The main idea of this approach is to check if the area of
// triangle T is equal to the sum of areas of sub triangles
// ABP, BCP, and ACP. Then the point P lies inside the triangle T. Otherwise, it’s outside.
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	return false;
}
