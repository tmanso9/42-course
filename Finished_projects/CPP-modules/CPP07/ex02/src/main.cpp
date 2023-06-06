/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:35:17 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/26 17:53:46 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>

int	main(void)
{
	{
		LOG("---Creating an empty int array---");
		Array<int>	a;
		std::cout << "Array size: " << a.size() << std::endl;
		try
		{
			std::cout << "a[0] = ";
			std::cout << a[0] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		LOG("\n---Creating a float array of size 42 with default values---");
		Array<float>	a(42);
		std::cout << "Array size: " << a.size() << std::endl;
		
		float	*b = new float[42];
		try
		{
			LOG("Comparing initial values with another float array of size 42...");
			unsigned int i = 0;
			for (; i < a.size() ; i++) {
				if (a[i] != b[i]) {
					std::cerr << i << ":\tUps, initialized with wrong number" << std::endl;
					break ;
				}
			}
			if (i == a.size()) {
				std::cout << "[ OK ]" << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete [] b;
	}
	{
		LOG("\n---Testing copy constructors and assignment operator---");
		LOG("Initializing Array<int> a(4); Array<int> b(a); Array<int> c = a");
		Array<int>	a(4);
		Array<int>	b(a);
		Array<int>	c = a;
		
		try
		{
			LOG("Checking initial values...");
			unsigned int i = 0;
			for (; i < a.size() ; i++) {
				if (b[i] != a[i] || c[i] != a[i]) {
					std::cerr << i << ":\tUps, initialized with wrong number" << std::endl;
					break ;
				}
			}
			if (i == a.size()) {
				std::cout << "[ OK ]" << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			LOG("Checking if changes in one array affect the others...");
			std::cout << "a[2] = " << a[2] << ";\tb[2] = " << b[2] << ";\tc[2] = " << c[2] << std::endl;
			a[2] = 72;
			std::cout << "a[2] = " << a[2] << ";\t\tb[2] = " << b[2] << ";\tc[2] = " << c[2] << std::endl;
			b[2] = -47;
			c[2] = 180;
			std::cout << "a[2] = " << a[2] << ";\t\tb[2] = " << b[2] << ";\t\tc[2] = " << c[2] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			LOG("Now value check will be wrong");
			unsigned int i = 0;
			for (; i < a.size() ; i++) {
				if (b[i] != a[i] || c[i] != a[i]) {
					std::cerr << "index " << i << ":\tValues are different" << std::endl;
					break ;
				}
			}
			if (i == a.size()) {
				std::cout << "[ OK ]" << std::endl;
			}
			
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	{
		LOG("\n---Testing [] operator with string array of size 512---");
		Array<std::string>	a(512);
		
		try
		{
			std::cout << "a[-40] = ";
			std::cout << a[-40] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			std::cout << "a[5000] = ";
			std::cout << a[5000] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			std::cout << "a[67] = ";
			std::cout << a[67] << std::endl;
			LOG("If value is changed to 'Hello world':");
			a[67] = "Hello world";
			std::cout << "a[67] = ";
			std::cout << a[67] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		#define MAX_VAL 750
		
		LOG("\n---downloaded main.cpp from the project page---");
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
}
