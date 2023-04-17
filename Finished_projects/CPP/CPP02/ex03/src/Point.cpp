/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:31:01 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/01 01:30:47 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
	// std::cout << "Default POINT constructor called" << std::endl;
}

Point::Point( const float x, const float y ) : _x(x), _y(y)
{
	// std::cout << "POINT float constructor called" << std::endl;
}

Point::Point( Point const & src ) : _x(src.getXValue()), _y(src.getYValue())
{
	// std::cout << "POINT Copy constructor called" << std::endl;
}

Point::~Point()
{
	// std::cout << "POINT destructor called" << std::endl;
}

Point &	Point::operator=( Point const & src )
{
	(Fixed &)this->_x = src._x;
	(Fixed &)this->_y = src._y;

	return *this;
}

float	Point::getXValue ( void ) const
{
	return (this->_x.toFloat());
}

float	Point::getYValue ( void ) const
{
	return (this->_y.toFloat());
}
