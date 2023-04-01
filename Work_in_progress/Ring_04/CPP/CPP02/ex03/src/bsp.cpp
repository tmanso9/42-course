/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:13:30 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/01 01:30:26 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

float	area(float Ax, float Ay, float Bx, float By, float Cx, float Cy)
{
	return std::fabs((Bx - Ax) * (Cy - Ay) - (Cx - Ax) * (By - Ay)) / 2.0;
}

bool	bsp( Point const a, Point const b, Point const c, Point const other)
{
	float	Ax = a.getXValue();
	float	Ay = a.getYValue();
	float	Bx = b.getXValue();
	float	By = b.getYValue();
	float	Cx = c.getXValue();
	float	Cy = c.getYValue();
	float	Px = other.getXValue();
	float	Py = other.getYValue();

	if ((Px == Ax && Py == Ay) || (Px == Bx && Py == By) || (Px == Cx && Py == Cy))
		return false;

	float	triangleArea = area(Ax, Ay, Bx, By, Cx, Cy);	
	float	pab = area(Px, Py, Ax, Ay, Bx, By);
	float	pbc = area(Px, Py, Bx, By, Cx, Cy);
	float	pca = area(Px, Py, Cx, Cy, Ax, Ay);
	
	if (pab == 0 || pbc == 0 || pca == 0)
        return false;
	if (triangleArea == pab + pbc + pca)
		return true;
	else
		return false;
	
}