/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:37:33 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/16 10:38:55 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point {
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point & rhs);
		~Point(void);

		Point&	operator=(const Point& rhs);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};
