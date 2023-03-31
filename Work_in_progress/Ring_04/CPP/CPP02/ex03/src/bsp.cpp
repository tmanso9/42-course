/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:13:30 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/31 18:26:46 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const other)
{
	std::cout << a.getXValue() << "  " << a.getYValue() << std::endl;
	std::cout << b.getXValue() << "  " << b.getYValue() << std::endl;
	std::cout << c.getXValue() << "  " << c.getYValue() << std::endl;
	std::cout << other.getXValue() << "  " << other.getYValue() << std::endl;

	if (other.getXValue() == a.getXValue() && other.getYValue() == a.getYValue())
		return false;
	if (other.getXValue() == b.getXValue() && other.getYValue() == b.getYValue())
		return false;
	if (other.getXValue() == c.getXValue() && other.getYValue() == c.getYValue())
		return false;
	// check if triangle possible
	// check if point in triangle
	std::cout << "*** STILL HERE ***" << std::endl;
	return true;

}