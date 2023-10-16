/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:30:19 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/10 16:23:48 by meskelin         ###   ########.fr       */
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

		bool	operator>(Fixed	& rhs) const;
		bool	operator<(Fixed	& rhs) const;
		bool	operator<=(Fixed & rhs) const;
		bool	operator>=(Fixed & rhs) const;
		bool	operator==(Fixed & rhs) const;
		bool	operator!=(Fixed & rhs) const;

		Fixed	operator+(Fixed & rhs) const;
		Fixed	operator-(Fixed & rhs) const;
		Fixed	operator*(Fixed & rhs) const;
		Fixed	operator/(Fixed & rhs) const;

		Fixed&	operator++(void); // prefix
		Fixed	operator++(int); // postfix
		Fixed&	operator--(void); // prefix
		Fixed	operator--(int); // postfix

		static Fixed&		min(Fixed &a, Fixed &b);
		static const Fixed&	min(const Fixed &a, const Fixed &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		static const Fixed&	max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &nbr);
