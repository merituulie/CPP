/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:30:14 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/03 23:15:11 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const nbr) : _fixedPointValue(nbr << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const nbr) : _fixedPointValue(std::roundf(nbr * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();

	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
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

Fixed	Fixed::operator+(Fixed &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed & rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed&	Fixed::operator++(void)
{
	++this->_fixedPointValue;
	return *this;
{

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	operator++();
	return temp;
}

Fixed&	Fixed::operator--(void)
{
	--this->_fixedPointValue;
	return this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	operator--();
	return temp;
}

static Fixed& min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

static const Fixed&	min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

static Fixed& max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

static const Fixed&	max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
