/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:02:49 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/13 14:57:16 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int	_n;
	static const int	_bits = 8;
	
public:

	Fixed( void );
	Fixed( Fixed const & src );
	Fixed( const int a );
	Fixed( const float a );
	~Fixed( void );

	Fixed &	operator=( Fixed const & src );

	int		getRawBits ( void ) const;
	void	setRawBits (int const raw);
	float	toFloat ( void ) const;
	int		toInt	( void ) const;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & num);

#endif