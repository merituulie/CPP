/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:30:14 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/16 10:43:35 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
}

Fixed::Fixed(int const nbr) : _fixedPointValue(nbr << _fractionalBits)
{
}

Fixed::Fixed(float const nbr) : _fixedPointValue(std::roundf(nbr * (1 << _fractionalBits)))
{
}

Fixed::Fixed(Fixed const &rhs)
{
	*this = rhs;
}

Fixed::~Fixed(void)
{
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();

	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> _fractionalBits;
}

float Fixed::toFloat(void) const
{
	return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &nbr)
{
	out << nbr.toFloat();
	return out;
}

bool Fixed::operator>(Fixed &rhs) const
{
	return this->getRawBits() > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed	&rhs) const
{
	return this->getRawBits() < rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed &rhs) const
{
	return this->getRawBits() <= rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed &rhs) const
{
	return this->getRawBits() >= rhs.getRawBits();
}

bool	Fixed::operator==(Fixed &rhs) const
{
	return this->getRawBits() == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed &rhs) const
{
	return this->getRawBits() != rhs.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed&	Fixed::operator++(void)
{
	++this->_fixedPointValue;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	operator++();
	return temp;
}

Fixed&	Fixed::operator--(void)
{
	--this->_fixedPointValue;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	operator--();
	return temp;
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
