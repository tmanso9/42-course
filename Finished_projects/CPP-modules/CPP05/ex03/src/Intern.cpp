/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:08:25 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/19 18:09:34 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
	LOG("Intern constructor called");
}

Intern::Intern( Intern const & src )
{
	LOG("Intern copy constructor called");
	(void)src;
}

Intern & Intern::operator=( Intern const & src )
{
	LOG("Intern assignment called");
	(void)src;
	return *this;
}

Intern::~Intern()
{
	LOG("Intern destructor called");
}

AForm*		Intern::makeShrubberyCreation( std::string target )
{
	return new ShrubberyCreationForm(target);
}

AForm*		Intern::makeRobotomyRequest( std::string target )
{
	return new RobotomyRequestForm(target);
}

AForm*		Intern::makePresidentialPardon( std::string target )
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm( std::string formType, std::string target )
{
	int i = 0;
	while (i < 3 && formType != knownForms[i])
		i++;
	for (int j = 0; j < 3; j++)
	{
		if (i == j) {
			std::cout << "Intern creates " << formType << std::endl;
			return (this->*f[i])(target);
		}
	}
	std::cout << "Intern doesn't know how to make a " << formType << " form." << std::endl;
	return NULL;
}

std::string	Intern::knownForms[3] = {
	"shrubbery creation", 
	"robotomy request", 
	"presidential pardon"
};

AForm*	(Intern::*Intern::f[3])(std::string) = {
	&Intern::makeShrubberyCreation,
	&Intern::makeRobotomyRequest,
	&Intern::makePresidentialPardon
};