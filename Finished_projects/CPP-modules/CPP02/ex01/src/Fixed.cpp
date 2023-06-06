/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:02:56 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/18 18:31:15 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "\033[0;32mDefault constructor called\033[0m" << std::endl;
	this->_n = 0;
}

Fixed::~Fixed( void )
{
	std::cout << "\033[0;31mDestructor called\033[0m" << std::endl;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "\033[0;32mCopy constructor called\033[0m" << std::endl;
	*this = src;
}

Fixed::Fixed( const int a )
{
	std::cout << "\033[0;32mInt constructor called\033[0m" << std::endl;
	this->setRawBits(a << _bits);
}

Fixed::Fixed( const float a )
{
	std::cout << "\033[0;32mFloat constructor called\033[0m" << std::endl;
	this->setRawBits(roundf(a * (1 << _bits)));
}

Fixed &	Fixed::operator=(Fixed const & src)
{
	std::cout << "\033[0;32mCopy assignment operator called\033[0m" << std::endl;
	this->setRawBits(src.getRawBits());
	return (*this);
}

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

std::ostream &	operator<<(std::ostream & out, Fixed const & num)
{
	out << num.toFloat();
	return out;
}
