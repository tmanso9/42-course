/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:31:01 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/31 16:11:19 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
	std::cout << "Default point constructor called" << std::endl;
}

Point::Point( const float x, const float y ) : _x(x), _y(y)
{
	std::cout << "Point float constructor called" << std::endl;
	std::cout << "X and Y initialized to " << x << " and " << y << std::endl;
}

Point::Point( Point const & src ) : _x(src.getXValue()), _y(src.getYValue())
{
	std::cout << "Copy constructor called" << std::endl;
}

Point::~Point()
{
	std::cout << "Point destructor called" << std::endl;
}

Point &	Point::operator=( Point const & src )
{
	if (this == &src)
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