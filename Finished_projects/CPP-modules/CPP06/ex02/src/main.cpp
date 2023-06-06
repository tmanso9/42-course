/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:35:17 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/25 15:06:47 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base	*generate( void );
void	identify(Base & p);
void	identify(Base* p);

int	main(void)
{
	std::srand(time(NULL));
	
	Base *base = generate();
	
	std::cout << "ID by pointer:\t\t";
	identify(base);
	std::cout << "ID by reference:\t";
	identify(*base);

	delete base;
}

Base	*generate( void )
{
	int	random = std::rand() % 3;
	switch (random)
	{
	case 0:
		return new A;
		break;
	case 1:
		return new B;
		break;
	default:
		return new C;
		break;
	}
}

void	identify(Base* p)
{
	A*	a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	B*	b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	C*	c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << "C" << std::endl;
		return ;
	}
}

void	identify(Base & p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
}
