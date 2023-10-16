/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:25:35 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/16 10:54:04 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float	get_area(Point x, Point y, Point j)
{
	float area = ((x.getX().toFloat() * (y.getY().toFloat() - j.getY().toFloat()))
		+ (y.getX().toFloat() * (j.getY().toFloat() - x.getY().toFloat()))
		+ (j.getX().toFloat() * (x.getY().toFloat() - y.getY().toFloat()))) / 2;

	if (area < 0)
		area = area * -1.0;
	return area;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float area_triangle = get_area(a, b, c);

	float area_abp = get_area(a, b, point);
	if (area_abp == 0)
		return false;
	float area_acp = get_area(a, c, point);
	if (area_acp == 0)
		return false;
	float area_bcp = get_area(b, c, point);
	if (area_bcp == 0)
		return false;

	float area_sum = area_abp + area_acp + area_bcp;
	std::cout << "Area of partitioned triangles: " << area_sum << std::endl;
	std::cout << "Area of original triangle: " << area_triangle << std::endl;
	return area_sum == area_triangle;
}
