/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:32:46 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/01 01:44:30 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main ( void )
{
	Point	a( -3.0f, -5.0f);
	Point	b(7.0f, -3.0f);
	Point	c ( 2.0f, 8.0f );

	float	vals[10][2];
	vals[0][0] = 2.0f;
	vals[0][1] = -4.0f;
	vals[1][0] = 1.0f;
	vals[1][1] = -4.0f;
	vals[2][0] = -2.0f;
	vals[2][1] = -4.0f;
	vals[3][0] = 20.0f;
	vals[3][1] = -4.0f;

	
	Point	Tests[10];
	
	Tests[0] = Point( vals[0][0], vals[0][1] );
	Tests[1] = Point( vals[1][0], vals[1][1] );
	Tests[2] = Point( vals[2][0], vals[2][1] );
	Tests[3] = Point( vals[3][0], vals[3][1] );
	Tests[4] = Point( 2.0f, -4.0f );
	Tests[5] = Point( 2.0f, -4.0f );
	Tests[6] = Point( 2.0f, -4.0f );
	Tests[7] = Point( 2.0f, -4.0f );
	Tests[8] = Point( 2.0f, -4.0f );
	Tests[9] = Point( 2.0f, -4.0f );

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Point (" << vals[i][0] << "," << vals[i][1] << ") "; 
		if (bsp(a, b, c, Tests[i]))
			std::cout << "is inside the triangle!" << std::endl;
		else
			std::cout << "is outside." << std::endl;
	}
}