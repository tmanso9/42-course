/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:02:56 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/30 18:33:00 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
}

Fixed &	Fixed::operator=(Fixed const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_n = src.getRawBits();
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

const int Fixed::_bits = 8;