/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:27:37 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/13 15:25:48 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;
	
public:
	Point( void );
	Point( Point const & src );
	Point( const float x, const float y );
	~Point( void );

	Point &	operator=( Point const & src );
	float	getXValue( void ) const;
	float	getYValue( void ) const;
};

bool	bsp( Point const a, Point const b, Point const c, Point const Point);

#endif