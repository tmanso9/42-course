/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:25:56 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/17 12:07:27 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void )
{
	LOG("Void Bureaucrat constructor called");
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
	std::cout << "Named constructor called for " << name << std::endl;
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		this->_grade = grade;
	}
	catch(GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

Bureaucrat::Bureaucrat( Bureaucrat const & src )
{
	LOG("Bureaucrat copy constructor called");
	*this = src;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & src )
{
	LOG("Bureaucrat assignment overload called");
	this->_name = src.getName();
	this->_grade = src.getGrade();
	
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	LOG("Bureaucrat destructor called");
}

std::string	Bureaucrat::getName(void) const
{
	return _name;
}

int	Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::incrementGrade(void)
{
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	_grade++;
}

std::ostream &	operator<<(std::ostream & out, Bureaucrat const & src )
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return out;
}

