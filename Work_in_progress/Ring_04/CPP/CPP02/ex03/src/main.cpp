/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:32:46 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/03 14:58:34 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main ( void )
{
	Point	a( -3.0f, -5.0f);
	Point	b(7.0f, -3.0f);
	Point	c ( 2.0f, 8.0f );

	std::cout << std::endl << "*** Drawing a triangle with vertices at (-3, -5), (2, 8), (7, -3) ***" << std::endl;
	std::cout << "Check it out at https://www.easycalculation.com/analytical/draw-triangle.php" << std::endl << std::endl ;

	Point	Tests[10];
	Tests[0] = Point( 2.0f, -4.0f );
	Tests[1] = Point( 2.0f, -3.8f );
	Tests[2] = Point( -2.0f, 6.0f );
	Tests[3] = Point( 5.0f, 0.004f );
	Tests[4] = Point( 2.0f, 7.99f );

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Point ( " << Tests[i].getXValue() << " , " << Tests[i].getYValue() << " ) "; 
		if (bsp(a, b, c, Tests[i]))
			std::cout << "\033[0;32mis inside the triangle.\033[0m" << std::endl;
		else
			std::cout << "\033[0;31mis outside.\033[0m" << std::endl;
	}

	std::cout << std::endl;
}