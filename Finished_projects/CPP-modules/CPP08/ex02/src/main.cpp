/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:35:17 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/30 21:31:57 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <string>

# define LOG(x) std::cout << x << std::endl;

int	main(void)
{
	{
		LOG("----Testing original main----");
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		
		LOG("----Comparing results with std::list----");
		std::list<int> ltest;
		ltest.push_back(5);
		ltest.push_back(17);
		std::cout << ltest.back() << std::endl;
		ltest.pop_back();
		std::cout << ltest.size() << std::endl;
		ltest.push_back(3);
		ltest.push_back(5);
		ltest.push_back(737);
		ltest.push_back(0);
		std::list<int>::iterator it2 = ltest.begin();
		std::list<int>::iterator ite2 = ltest.end();
		++it2;
		--it2;
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
	}
	{
		LOG("\n----Now for my own main----");
		MutantStack<int> a;

		a.push(45);
		a.push(47);
		a.push(49);
		a.push(100);

		MutantStack<int>::iterator it = a.begin();
		MutantStack<int>::iterator it2 = it;
		it++;
		it--;
		for (; it2 != a.end(); it2++) {
			std::cout << *it2 << " ";
		}
		std::cout << std::endl;
		a.pop();
		for (; it != a.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		a.push(33);
		a.push(-33);
		a.push(330);
		a.push(3300);
		a.push(33333);
		it = a.begin();
		for (; it != a.end(); it++) {
			std::cout << *it << " ";
		}

		std::cout << std::endl;
		MutantStack<int>::reverse_iterator rit = a.rbegin();
		for (; rit != a.rend(); rit++) {
			std::cout << *rit << " ";
		}

		MutantStack<std::string> S;
		S.push("oi");
		S.push("teste");
		S.push("jehdvjsh jdscgjh");

		std::cout << std::endl;
		MutantStack<std::string>::const_iterator Sit = S.begin();
		for (; Sit != S.end(); Sit++) {
			std::cout << *Sit << "\t";
		}
	}
	
}
