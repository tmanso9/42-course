/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:02:56 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/30 19:47:38 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors */
Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->_n = 0;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed( const int a )
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(a << _bits);
}

Fixed::Fixed( const float a )
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(a * (1 << _bits)));
	this->_n_float = a;
}

/* Overloads */
Fixed &	Fixed::operator=(Fixed const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_n = src.getRawBits();
	return (*this);
}

bool	Fixed::operator>( Fixed const & src ) const
{
	std::cout << "Bigger than operator called" << std::endl;
	return (this->toFloat() > src.toFloat());
}

bool	Fixed::operator<( Fixed const & src ) const
{
	std::cout << "Less than operator called" << std::endl;
	return (this->toFloat() < src.toFloat());
}

bool	Fixed::operator>=( Fixed const & src ) const
{
	std::cout << "Bigger than or equal operator called" << std::endl;
	return (this->toFloat() >= src.toFloat());
}

bool	Fixed::operator<=( Fixed const & src ) const
{
	std::cout << "Less than or equal operator called" << std::endl;
	return (this->toFloat() <= src.toFloat());
}

bool	Fixed::operator==( Fixed const & src ) const
{
	std::cout << "Equal operator called" << std::endl;
	return (this->toFloat() == src.toFloat());
}

bool	Fixed::operator!=( Fixed const & src ) const
{
	std::cout << "Different operator called" << std::endl;
	return (this->toFloat() != src.toFloat());
}

Fixed	Fixed::operator+(Fixed const & src) const
{
	std::cout << "Plus operator called" << std::endl;
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed	Fixed::operator-(Fixed const & src) const
{
	std::cout << "Minus operator called" << std::endl;
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed	Fixed::operator*(Fixed const & src) const
{
	std::cout << "Multiplication operator called" << std::endl;
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed	Fixed::operator/(Fixed const & src) const
{
	std::cout << "Division operator called" << std::endl;
	return Fixed(this->toFloat() / src.toFloat());
}

std::ostream &	operator<<(std::ostream & out, Fixed const & num)
{
	out << num.toFloat();
	return out;
}

Fixed &	Fixed::operator++( void )
{
	std::cout << "Pre-increment operator called" << std::endl;

	if (this->toFloat())
		this->setRawBits(roundf(this->toFloat() * (1 << _bits)) + roundf(this->toFloat() * (1 << _bits)));
	else
		std::cout << (int)((1.0f / (1 << _bits))) << std::endl;

	std::cout << "What is this? " << this->toFloat() << std::endl;
	exit(0);
	return (*this);
}

Fixed &	Fixed::operator--( void )
{
	std::cout << "Pre-decrement operator called" << std::endl;
	this->setRawBits(this->getRawBits() - this->getRawBits());
	return (*this);
}

Fixed	Fixed::operator++( int none )
{
	(void)none;
	float	old = this->toFloat();
	this->setRawBits(this->getRawBits() + this->getRawBits());
	return Fixed(old);
}

Fixed	Fixed::operator--( int none )
{
	(void)none;
	float	old = this->toFloat();
	this->setRawBits(this->getRawBits() - this->getRawBits());
	return Fixed(old);
}

/* Member functions */
int	Fixed::getRawBits( void ) const
{
	return (this->_n);
}

void	Fixed::setRawBits (int const raw)
{
	this->_n = raw;
}

int		Fixed::toInt ( void ) const
{
	return this->getRawBits() >> _bits;
}

float		Fixed::toFloat(void) const
{
	return (float)this->getRawBits() / (1 << _bits) ;
}

/* Static definitions */
const int Fixed::_bits = 8;