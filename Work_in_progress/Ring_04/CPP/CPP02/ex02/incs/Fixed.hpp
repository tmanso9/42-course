/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:02:49 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/30 19:38:52 by touteiro         ###   ########.fr       */
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
	float	_n_float;
	static const int	_bits;
	
public:

	Fixed( void );
	Fixed( Fixed const & src );
	Fixed( const int a );
	Fixed( const float a );
	~Fixed( void );

	Fixed &	operator=( Fixed const & src );
	bool	operator>( Fixed const & src ) const;
	bool	operator<( Fixed const & src ) const;
	bool	operator>=( Fixed const & src ) const;
	bool	operator<=( Fixed const & src ) const;
	bool	operator==( Fixed const & src ) const;
	bool	operator!=( Fixed const & src ) const;

	Fixed	operator+( Fixed const & src ) const;
	Fixed	operator-( Fixed const & src ) const;
	Fixed	operator*( Fixed const & src ) const;
	Fixed	operator/( Fixed const & src ) const;
	
	Fixed &	operator++( void );
	Fixed &	operator--( void );
	Fixed	operator++( int none );
	Fixed	operator--( int none );
	
	int		getRawBits ( void ) const;
	void	setRawBits (int const raw);
	float	toFloat ( void ) const;
	int		toInt	( void ) const;
	
};

std::ostream &	operator<<(std::ostream & o, Fixed const & num);

#endif