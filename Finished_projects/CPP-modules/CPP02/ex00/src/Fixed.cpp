/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:02:56 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/13 14:57:40 by touteiro         ###   ########.fr       */
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

Fixed &	Fixed::operator=(Fixed const & src)
{
	std::cout << "\033[0;32mCopy assignment operator called\033[0m" << std::endl;
	this->setRawBits(src.getRawBits());
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
