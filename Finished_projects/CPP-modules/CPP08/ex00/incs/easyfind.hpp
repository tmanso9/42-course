/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:35:45 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/26 20:33:27 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>

class notFoundException : public std::exception
{
	public:
		virtual const char* what() const throw() { return "Value not found"; };
};

template<typename T>
typename T::iterator	easyfind( T & cont, int n )
{
	typename T::iterator res = std::find(cont.begin(), cont.end(), n);
	if (res == cont.end()) {
		throw notFoundException();
	}
	return res;
};

#endif