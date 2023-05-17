/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:35:17 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/17 19:27:21 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

void	logAttempt( std::string name, int grade)
{
	std::cout << "Trying to construct a bureaucrat named " << name << " with a grade of " << grade << "..." << std::endl;
}

int	main(void)
{
	PresidentialPardonForm	a("home");

	std::cout << a;
}