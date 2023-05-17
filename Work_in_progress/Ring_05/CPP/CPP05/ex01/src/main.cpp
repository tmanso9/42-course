/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:35:17 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/17 18:45:37 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	logAttempt( std::string name, int grade)
{
	std::cout << "Trying to construct a bureaucrat named " << name << " with a grade of " << grade << "..." << std::endl;
}

int	main(void)
{
	{
		try
		{
			logAttempt("Marvin", 5);
			Bureaucrat	Marvin("Marvin", 5);
			LOG("\033[1;28mConstruction successful! Printing info:\033[0;m");
			std::cout << Marvin;
			try
			{
				LOG("\nCreating form 28A with min grade 151");
				Form	x("28A", 151, 100);
				Marvin.signForm(x);
				std::cout << x;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Form construction failed because " << e.what() << '\n';
			}
			try
			{
				LOG("\nCreating form 28B with min grade -2");
				Form	x("28B", -2, 100);
				Marvin.signForm(x);
				std::cout << x;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Form construction failed because " << e.what() << '\n';
			}
			try
			{
				LOG("\nCreating form 28C with min grade 4");
				Form	x("28C", 4, 100);
				LOG("Creating form 28D with min grade 10");
				Form	y("28D", 10, 100);
				Marvin.signForm(x);
				std::cout << x;
				Marvin.signForm(y);
				std::cout << y;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Form construction failed because " << e.what() << '\n';
			}
			
		}
		catch(const std::exception& e)
		{
			std::cerr << "Construction failed because " << e.what() << ".\n";
		}
	}
}