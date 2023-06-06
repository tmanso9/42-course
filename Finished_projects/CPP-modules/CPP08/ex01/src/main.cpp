/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:35:17 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/31 16:26:14 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	/* Aux vector to fill Span vector */
	std::srand(time(NULL));
	std::vector<int>	toFill;
	for (int i = 0; i < 5000000; i++) {
		toFill.push_back(rand() - (INT_MAX / 2));
	}
	
	std::cout << "\t[Failed cases]" << std::endl;
	try
	{
		std::cout << "\n<Adding number to array of size 0>" << std::endl;
		Span wrong = Span(0);
		wrong.addNumber(54);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << "\n<Filling a full array>" << std::endl;
		Span wrong = Span(10);
		wrong.addNumber(54, 85);
		std::cout << "First time worked" << std::endl;
		wrong.addNumber(54, 85);
		std::cout << "Second time worked" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\n<Reading span of array of size 1>" << std::endl;
		Span wrong = Span(1);
		wrong.addNumber(35);
		if (wrong.getArr().size()) {
			std::cout << wrong << std::endl;
			std::cout << "array size:\t" << wrong.getArr().size() << std::endl;
			std::cout << "max value:\t" << *std::max_element(wrong.getArr().begin(), wrong.getArr().end()) << std::endl;
			std::cout << "min value:\t" << *std::min_element(wrong.getArr().begin(), wrong.getArr().end()) << std::endl;
		}
		std::cout << "shortest span:\t" << wrong.shortestSpan() << std::endl;
		std::cout << "longest span:\t" << wrong.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << "------------------------------" << std::endl << std::endl;
	std::cout << "\t[Working cases]" << std::endl;
	
	Span sp = Span(450000);
	try
	{
		std::cout << "\n\t[Small array]" << std::endl << std::endl;
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		if (sp.getArr().size()) {
			std::cout << sp << std::endl;
			std::cout << "array size:\t" << sp.getArr().size() << std::endl;
			std::cout << "max value:\t" << *std::max_element(sp.getArr().begin(), sp.getArr().end()) << std::endl;
			std::cout << "min value:\t" << *std::min_element(sp.getArr().begin(), sp.getArr().end()) << std::endl;
		}
		std::cout << "\nshortest span:\t" << sp.shortestSpan() << std::endl;
		std::cout << "longest span:\t" << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	sp.getArr().clear();
	std::cout << std::endl << "------------------------------" << std::endl << std::endl;
	try
	{
		std::cout << "\t[50 random ints array]" << std::endl << std::endl;
		sp.addNumber(toFill.begin(), toFill.begin() + 50);
		if (sp.getArr().size()) {
			std::cout << sp << std::endl;
			std::cout << "array size:\t" << sp.getArr().size() << std::endl;
			std::cout << "max value:\t" << *std::max_element(sp.getArr().begin(), sp.getArr().end()) << std::endl;
			std::cout << "min value:\t" << *std::min_element(sp.getArr().begin(), sp.getArr().end()) << std::endl;
		}
		std::cout << "\nshortest span:\t" << sp.shortestSpan() << std::endl;
		std::cout << "longest span:\t" << sp.longestSpan() << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << "------------------------------" << std::endl << std::endl;
	try
	{
		std::cout << "\t[Big random ints array -- added with iterators]" << std::endl << std::endl;
		sp.addNumber(toFill.begin(), toFill.end());
		if (sp.getArr().size()) {
			std::cout << "array size:\t" << sp.getArr().size() << std::endl;
			std::cout << "max value:\t" << *std::max_element(sp.getArr().begin(), sp.getArr().end()) << std::endl;
			std::cout << "min value:\t" << *std::min_element(sp.getArr().begin(), sp.getArr().end()) << std::endl;
		}
		std::cout << "\nshortest span:\t" << sp.shortestSpan() << std::endl;
		std::cout << "longest span:\t" << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	sp.getArr().clear();
	std::cout << std::endl << "------------------------------" << std::endl << std::endl;
	try
	{
		std::cout << "\t[Big random ints array -- added with range]" << std::endl << std::endl;
		sp.addNumber(-10, 0);
		if (sp.getArr().size()) {
			std::cout << "array size:\t" << sp.getArr().size() << std::endl;
			std::cout << "max value:\t" << *std::max_element(sp.getArr().begin(), sp.getArr().end()) << std::endl;
			std::cout << "min value:\t" << *std::min_element(sp.getArr().begin(), sp.getArr().end()) << std::endl;
		}
		std::cout << "\nshortest span:\t" << sp.shortestSpan() << std::endl;
		std::cout << "longest span:\t" << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
