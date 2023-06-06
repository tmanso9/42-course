/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:09:15 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/19 17:25:48 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form( void )
	:
		_name("default"),
		_signed(false),
		_toSign(1),
		_toExecute(1)
{
	LOG("Form default constructor called");
}

Form::Form( Form const & src)
	:
		_name(src.getName()),
		_signed(src.getSigned()),
		_toSign(src.getToSign()),
		_toExecute(src.getToExecute())
{
	LOG("Form copy constructor called");
}

Form & Form::operator=( Form const & src )
{
	this->_signed = src.getSigned();

	return *this;
}

Form::~Form()
{
	std::cout << "Destructor called for form " << _name << "." << std::endl;
}

Form::Form( std::string name, int toSign, int toExecute )
	:
		_name(name),
		_signed(false),
		_toSign(toSign),
		_toExecute(toExecute)
{
	std::cout << "Constructor called for form " << _name << "." << std::endl;
	if (toSign < 1 || toExecute < 1)
		throw GradeTooHighException();
	if (toSign > 150 || toExecute > 150)
		throw GradeTooLowException();
}

std::string	Form::getName( void ) const
{
	return _name;
}

bool	Form::getSigned( void ) const
{
	return _signed;
}

int	Form::getToSign( void ) const
{
	return _toSign;
}

int	Form::getToExecute( void ) const
{
	return _toExecute;
}

void	Form::beSigned( Bureaucrat const & src )
{
	if (src.getGrade() > _toSign)
		throw GradeTooLowException();
	_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

std::ostream & operator<<( std::ostream & out, Form const & src)
{
	out << "Form " << src.getName();
	out << " is " << (src.getSigned() ? "signed. " : "not signed. ");
	out << "You need grade " << src.getToSign() << " to sign it and ";
	out << src.getToExecute() << " to execute it."  << std::endl;
	return out;
}
