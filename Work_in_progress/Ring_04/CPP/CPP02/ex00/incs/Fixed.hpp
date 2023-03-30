/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:02:49 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/30 15:03:18 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int	_n;
	static const int	_bits;
	
public:

	Fixed( void );
	Fixed( Fixed const & a );
	~Fixed( void );

	int	getRawBits( void ) const;
	void	setRawBits (int const raw);
	Fixed	& operator=( Fixed const & rhs );
	// Fixed	operator+(Fixed const & rhs) const;
};




#endif