/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:32:46 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/01 01:28:06 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main ( void )
{
	Point	a( -3.0f, -5.0f);
	Point	b(7.0f, -3.0f);
	Point	c ( 2.0f, 8.0f );
	Point	Point ( 2.0f, -4.0f );

	if (bsp(a, b, c, Point))
		std::cout << "Point is inside triangle!" << std::endl;
	else
		std::cout << "No triangle for you!" << std::endl;
}