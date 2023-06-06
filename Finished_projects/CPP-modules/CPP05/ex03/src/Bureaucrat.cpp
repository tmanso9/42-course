/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:25:56 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/22 15:33:02 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

Bureaucrat::Bureaucrat( void ) : _name("default"), _grade(150)
{
	LOG("\033[0;32mVoid Bureaucrat constructor called\033[0;m");
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade)
{
	std::cout << "\033[0;32mNamed constructor called for " << name << "\033[0;m" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name(src.getName()), _grade(src.getGrade())
{
	LOG("\033[0;32mBureaucrat copy constructor called\033[0;m");
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & src )
{
	LOG("Bureaucrat assignment overload called");
	_grade = src.getGrade();
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	LOG("\033[0;31mBureaucrat destructor called\033[0;m");
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
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

void	Bureaucrat::signForm( AForm & src )
{
	try
	{
		src.beSigned( *this );
		std::cout << _name << " signed " << src.getName() << "." << std::endl;
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << _name << " couldn't sign " << src.getName() << " because " << e.what() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm( AForm const & form )
{
	try
	{
		form.execute( *this );
		std::cout << _name << " executed " << form.getName() << "." << std::endl;
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << ".\n";
	}
	catch(AForm::FormNotSignedException& e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << ".\n";
	}
	catch(ShrubberyCreationForm::FileNotCreatedException& e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << ".\n";
	}
}

std::ostream &	operator<<(std::ostream & out, Bureaucrat const & src )
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return out;
}

