/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:29:52 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/10 16:01:43 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(int const nrb);
		Fixed(float const nrb);
		Fixed(Fixed const & rhs);
		~Fixed(void);

		Fixed & operator=(Fixed const & rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt( void ) const;
		float	toFloat( void ) const;
};

std::ostream & operator<<(std::ostream &out, const Fixed &rhs);
