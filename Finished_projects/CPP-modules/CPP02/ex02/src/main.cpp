/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:32:46 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/13 15:22:46 by touteiro         ###   ########.fr       */
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
		
		std::cout << std::endl << "*** TESTING ARITHMETIC OPERATORS ***" << std::endl;
		Fixed	c(5.5f);
		std::cout << "c is " << c << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c + b: " << (c + b) << std::endl;
		std::cout << "c - b: " << (c - b) << std::endl;
		std::cout << "c * b: " << (c * b) << std::endl;
		std::cout << "c / b: " << (c / b) << std::endl;
		
		std::cout << std::endl << "*** TESTING INCREMENT OPERATORS ***" << std::endl;
		Fixed	d(0);
		std::cout << "d is " << d << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "++d: " << (++d) << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "++d: " << (++d) << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "d++: " << d++ << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << std::endl;
		std::cout << "*** TESTING MIN/MAX MEMBER FUNCTIONS ***" << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "Fixed::min(d, b): " << Fixed::min(d, b) << std::endl;
		std::cout << "Fixed::max(d, b): " << Fixed::max(d, b) << std::endl;
		std::cout << std::endl;
		const Fixed	e(3.2f);
		const Fixed	f(6.765f);
		std::cout << "e is " << e << std::endl;
		std::cout << "f is " << f << std::endl;
		std::cout << "Fixed::min(e, f): " << Fixed::min( e, f ) << std::endl;
		std::cout << "Fixed::max(e, f): " << Fixed::max( e, f ) << std::endl;

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