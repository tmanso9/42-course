/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:25:56 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/17 19:02:22 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("default"), _grade(150)
{
	// LOG("\033[0;32mVoid Bureaucrat constructor called\033[0;m");
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
	// std::cout << "\033[0;32mNamed constructor called for " << name << "\033[0;m" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src )
{
	// LOG("\033[0;32mBureaucrat copy constructor called\033[0;m");
	*this = src;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & src )
{
	// LOG("Bureaucrat assignment overload called");
	this->_name = src.getName();
	this->_grade = src.getGrade();
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
	
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	// LOG("\033[0;31mBureaucrat destructor called\033[0;m");
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
	if (_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade(void)
{
	_grade++;
	if (_grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::signForm( AForm & src )
{
	try
	{
		src.beSigned( *this );
		std::cout << _name << " signed " << src.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << src.getName() << " because " << e.what() << "." << std::endl;
	}
	
}

std::ostream &	operator<<(std::ostream & out, Bureaucrat const & src )
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return out;
}

