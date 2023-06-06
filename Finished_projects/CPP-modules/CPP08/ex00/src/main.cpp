/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:35:17 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/31 16:14:45 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>
#include <string>

#define LOG(x) std::cout << x << std::endl

int	main(void)
{
	{
		LOG("Testing with list container");
		std::list<int> lst;

		lst.push_back(32);
		lst.push_back(5);
		lst.push_back(1);
		lst.push_back(-7);
		lst.push_back(54);
		lst.push_back(32);
		try
		{
			std::list<int>::iterator it = easyfind(lst, 54);
			std::cout << "Found " << *it << std::endl;
			it--;
			std::cout << "Before is " << *it << std::endl;
			
			it = easyfind(lst, 32);
			std::cout << "Found " << *it << std::endl;
			it++;
			std::cout << "After is " << *it << std::endl;
			
			it = easyfind(lst, 876);
			std::cout << "Found " << *it << std::endl;
			it--;
			std::cout << "Before is " << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl;
		LOG("Testing with vector container");

		int	myArr[] = {35, 48, 77, -20};
		std::vector<int>	V(myArr, myArr + sizeof(myArr) / sizeof(int));

		std::cout << "Printing vector: ";
		for (std::vector<int>::iterator it = V.begin(); it != V.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		try
		{
			std::vector<int>::iterator it = easyfind(V, 48);
			std::cout << "Found " << *it << std::endl;
			it = easyfind(V, 560);
			std::cout << "Found " << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl;
		LOG("Testing with std::string");
		
		std::string str = "Hello World";
		try
		{
			std::string::iterator it = easyfind(str, 'e');
			std::cout << *it++ << std::endl;
			std::cout << *it << std::endl;
			std::cout << *easyfind(str, 'Z') << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
