/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:18:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/24 13:24:21 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cctype>
# include <cstdlib>
# include <string>
# include <cmath>
# include <limits>

# define LOG(x) std::cout << x << std::endl

class ScalarConverter
{
private:
	ScalarConverter( void );
	ScalarConverter( ScalarConverter const &);
	ScalarConverter & operator=( ScalarConverter const & );

	static float	toFloat;
	static double	toDouble;
	static char		toChar;
	static int		toInt;

	static void		printResult( char );
	static void		printResult( double );
	static void		printResult( float );
	static void		printResult( int );
	
	static void		impossiblePrint( bool );
	static bool		validFormat( std::string );
	static bool		isLimit( std::string );
public:
	~ScalarConverter();
	
	static void convert( std::string );
};

#endif
