/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:05:20 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/10 19:57:48 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*ptr = &str;
	// Reference is like an alias; 
	// pointer that is constant (always points to the same address), 
	// always dereferenced, 
	// never null (always needs to be initialized as soon as it is declared).
	std::string	&ref = str;

	std::cout << "First, let's print the memory addresses:" << std::endl;
	std::cout << "str:	  " << &str << std::endl;
	std::cout << "ptr holds " << ptr << std::endl;
	std::cout << "ref holds " << &ref << std::endl << std::endl;

	std::cout << "Now let's print the values inside:" << std::endl;
	std::cout << "str: " << str << std::endl;
	std::cout << "ptr: " << *ptr << std::endl;
	std::cout << "ref: " << ref << std::endl << std::endl;
}