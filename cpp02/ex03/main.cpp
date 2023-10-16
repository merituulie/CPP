/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:30:25 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/16 11:29:08 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	const Point a(0, 0);
	const Point b(10, 5.0);
	const Point c(1.0, 10);
	const Point w = c;
	const Point point1(5.0, 5.0);

	std::cout << "------------TEST 1-----------" << std::endl;
	if (bsp(a, b, w, point1) == true)
		std::cout << "Point is inside!" << std::endl;
	else
		std::cout << "Point is not inside!" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	const Point d(-1.5, -1.5);
	const Point e(2.5, 2.5);
	const Point f(-1, -2);
	const Point point2(8.5, -9);

	std::cout << "------------TEST 2-----------" << std::endl;
	if (bsp(d, e, f, point2) == true)
		std::cout << "Point is inside!" << std::endl;
	else
		std::cout << "Point is not inside!" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	const Point g(2.0, 1.0);
	const Point h(10.0, 10.0);
	const Point i(15.0, 8.0);
	const Point point3(5.0, 5.0);

	std::cout << "------------TEST 3-----------" << std::endl;
	if (bsp(g, h, i, point3) == true)
		std::cout << "Point is inside!" << std::endl;
	else
		std::cout << "Point is not inside!" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	Point j(2.0, 1.0);
	Point k(10.0, 10.0);
	Point l(15.0, 8.0);
	Point point4(5.0, 5.0);

	std::cout << "------------TEST 4-----------" << std::endl;
	if (bsp(j, k, l, point4) == true)
		std::cout << "Point is inside!" << std::endl;
	else
		std::cout << "Point is not inside!" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	return 0;
}
