/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:28:56 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/25 19:30:58 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap( T & a, T & b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T const & min( T const & x, T const & y) {
	return (x <= y ? x : y );
}

template<typename T>
T const & max( T const & x, T const & y) {
	return (x >= y ? x : y );
}

#endif // !WHATEVER_HPP