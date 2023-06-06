/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:35:17 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/26 11:38:44 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "iter.hpp"

int	main(void)
{
	int intArr[] = {3, 6, 8, 1, 0};
	
	::iter(intArr, 5, ::printVal);
	std::cout << std::endl;
	::iter(intArr, 5, ::timesTwo);
	::iter(intArr, 5, ::printVal);

	std::cout << std::endl << std::endl;
	
	float floatArr[] = {6.3f, -12.03f, .003f, 42.024f, 4e-1f};
	::iter(floatArr, 5, ::printVal);
	std::cout << std::endl;
	::iter(floatArr, 5, ::timesTwo);
	::iter(floatArr, 5, ::printVal);

	std::cout << std::endl << std::endl;
	
	std::string	text[] = {"Helllo", "I", "am", "a bunch of strings"};
	::iter(text, 4, ::printVal);
}
