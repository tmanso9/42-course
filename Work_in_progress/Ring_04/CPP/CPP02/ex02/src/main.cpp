/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:32:46 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/31 14:15:14 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main ( void )
{
	{
		Fixed	a;
		Fixed	b( 10 );

		std::cout << std::endl << "*** TESTING COMPARISONS ***" << std::endl;
		std::cout << "a is " << (a) << std::endl;
		std::cout << "b is " << (b) << std::endl;
		std::cout << "a > b: " << (a > b) << std::endl;
		std::cout << "a < b: " << (a < b) << std::endl;
		std::cout << "a >= b: " << (a >= b) << std::endl;
		std::cout << "a <= b: " << (a <= b) << std::endl;
		std::cout << "a == b: " << (a == b) << std::endl;
		std::cout << "a != b: " << (a != b) << std::endl;
		
		a = Fixed(5.1005f);
		std::cout << std::endl << "*** TESTING ARITHMETIC OPERATORS ***" << std::endl;
		std::cout << "a is " << (a) << std::endl;
		std::cout << "b is " << (b) << std::endl;
		std::cout << "a + b: " << (a + b) << std::endl;
		std::cout << "a - b: " << (a - b) << std::endl;
		std::cout << "a * b: " << (a * b) << std::endl;
		std::cout << "a / b: " << (a / b) << std::endl;
		
		a = Fixed(0);
		std::cout << std::endl << "*** TESTING INCREMENT OPERATORS ***" << std::endl;
		std::cout << "a is " << (a) << std::endl;
		std::cout << "b is " << (b) << std::endl;
		std::cout << "++a: " << (++a) << std::endl;
		std::cout << "a is " << a << std::endl;
		std::cout << "++a: " << (++a) << std::endl;
		std::cout << "a is " << a << std::endl;
		std::cout << "a++: " << a++ << std::endl;
		std::cout << "a is " << a << std::endl;

		std::cout << std::endl;
		std::cout << "*** TESTING MIN/MAX MEMBER FUNCTIONS ***" << std::endl;
		std::cout << "a is " << (a) << std::endl;
		std::cout << "b is " << (b) << std::endl;
		std::cout << "Fixed::min(a, b): " << Fixed::min(a, b) << std::endl;
		std::cout << "Fixed::max(a, b): " << Fixed::max(a, b) << std::endl;
		std::cout << std::endl;
		const Fixed	c(3.2f);
		const Fixed	d(6.765f);
		std::cout << "c is " << (c) << std::endl;
		std::cout << "d is " << (d) << std::endl;
		std::cout << "Fixed::min(c, d): " << Fixed::min( c, d ) << std::endl;
		std::cout << "Fixed::max(c, d): " << Fixed::max( c, d ) << std::endl;

		std::cout << std::endl << "*** REACHED END OF TESTS ***" << std::endl;
		

	}
/* 	{
		std::cout << std::endl;

		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		
		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	} */
}