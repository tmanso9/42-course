/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:02:56 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/30 15:08:38 by touteiro         ###   ########.fr       */
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

Fixed::Fixed( Fixed const & instance )
{
	std::cout << "Copy constructor called" << std::endl;
	Fixed::operator=( instance );
}

Fixed &	Fixed::operator=(Fixed const & instance)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_n = instance.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_n);
}

void	Fixed::setRawBits (int const raw)
{
	this->_n = raw;
}

const int Fixed::_bits = 8;