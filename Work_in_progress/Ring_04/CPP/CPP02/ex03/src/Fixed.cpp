/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:02:56 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/13 15:31:48 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors */
Fixed::Fixed( void )
{
	// std::cout << "\033[0;32mDefault constructor called\033[0m" << std::endl;
	this->_rawValue = 0;
}

Fixed::~Fixed( void )
{
	// std::cout << "\033[0;31mDestructor called\033[0m" << std::endl;
}

Fixed::Fixed( Fixed const & src )
{
	// std::cout << "\033[0;32mCopy constructor called\033[0m" << std::endl;
	*this = src;
}

Fixed::Fixed( const int a )
{
	// std::cout << "\033[0;32mInt constructor called\033[0m" << std::endl;
	this->setRawBits(a << _bits);
}

Fixed::Fixed( const float a )
{
	// std::cout << "\033[0;32mFloat constructor called\033[0m" << std::endl;
	this->setRawBits(roundf(a * (1 << _bits)));
}

/* Overloads */
Fixed &	Fixed::operator=(Fixed const & src)
{
	// std::cout << "\033[0;32mCopy assignment operator called\033[0m" << std::endl;
	this->setRawBits(src.getRawBits());
	return (*this);
}

bool	Fixed::operator>( Fixed const & src ) const
{
	// std::cout << "Bigger than operator called" << std::endl;
	return (this->getRawBits() > src.getRawBits());
}

bool	Fixed::operator<( Fixed const & src ) const
{
	// std::cout << "Less than operator called" << std::endl;
	return (this->getRawBits() < src.getRawBits());
}

bool	Fixed::operator>=( Fixed const & src ) const
{
	// std::cout << "Bigger than or equal operator called" << std::endl;
	return (this->getRawBits() >= src.getRawBits());
}

bool	Fixed::operator<=( Fixed const & src ) const
{
	// std::cout << "Less than or equal operator called" << std::endl;
	return (this->getRawBits() <= src.getRawBits());
}

bool	Fixed::operator==( Fixed const & src ) const
{
	// std::cout << "Equal operator called" << std::endl;
	return (this->getRawBits() == src.getRawBits());
}

bool	Fixed::operator!=( Fixed const & src ) const
{
	// std::cout << "Different operator called" << std::endl;
	return (this->getRawBits() != src.getRawBits());
}

Fixed	Fixed::operator+(Fixed const & src) const
{
	// std::cout << "Plus operator called" << std::endl;
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed	Fixed::operator-(Fixed const & src) const
{
	// std::cout << "Minus operator called" << std::endl;
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed	Fixed::operator*(Fixed const & src) const
{
	// std::cout << "Multiplication operator called" << std::endl;
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed	Fixed::operator/(Fixed const & src) const
{
	// std::cout << "Division operator called" << std::endl;
	return Fixed(this->toFloat() / src.toFloat());
}

std::ostream &	operator<<(std::ostream & out, Fixed const & num)
{
	out << num.toFloat();
	return out;
}

Fixed &	Fixed::operator++( void )
{
	// std::cout << "Pre-increment operator called" << std::endl;
	this->_rawValue++;
	return (*this);
}

Fixed &	Fixed::operator--( void )
{
	// std::cout << "Pre-decrement operator called" << std::endl;
	this->_rawValue--;
	return (*this);
}

Fixed	Fixed::operator++( int none )
{
	// std::cout << "Post-increment operator called" << std::endl;
	(void)none;
	float	old = this->toFloat();
	this->_rawValue++;
	return Fixed(old);
}

Fixed	Fixed::operator--( int none )
{
	// std::cout << "Post-decrement operator called" << std::endl;
	(void)none;
	float	old = this->toFloat();
	this->_rawValue--;
	return Fixed(old);
}

/* Member functions */
int	Fixed::getRawBits( void ) const
{
	return (this->_rawValue);
}

void	Fixed::setRawBits (int const raw)
{
	this->_rawValue = raw;
}

int		Fixed::toInt ( void ) const
{
	return this->getRawBits() >> _bits;
}

float		Fixed::toFloat(void) const
{
	return (float)this->getRawBits() / (1 << _bits) ;
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	// std::cout << "Min member function called" << std::endl;
	return (a < b ? a : b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	// std::cout << "Max member function called" << std::endl;
	return (a > b ? a : b);
}

const Fixed & Fixed::min( const Fixed & a, const Fixed & b)
{
	// std::cout << "Const min member function called" << std::endl;
	return (a < b ? a : b);
}

const Fixed & Fixed::max( const Fixed & a, const Fixed & b)
{
	// std::cout << "Const max member function called" << std::endl;
	return (a > b ? a : b);
}
