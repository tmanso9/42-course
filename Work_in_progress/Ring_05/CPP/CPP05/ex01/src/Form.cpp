/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:09:15 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/17 18:50:06 by touteiro         ###   ########.fr       */
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
	// LOG("Form void constructor called");
}

Form::Form( Form const & src)
	:
		_name(src.getName()),
		_signed(src.getSigned()),
		_toSign(src.getToSign()),
		_toExecute(src.getToExecute())
{
	// LOG("Form copy constructor called");
}

Form & Form::operator=( Form const & src )
{
	this->_name = src.getName();
	this->_signed = src.getSigned();
	this->_toSign = src.getToSign();
	this->_toExecute = src.getToExecute();

	return *this;
}

Form::~Form()
{
	// std::cout << "Destructor called for " << _name << " form" << std::endl;
}

Form::Form( std::string name, int toSign, int toExecute )
	:
		_name(name),
		_signed(false)
{
	if (toSign < 1 || toExecute < 1)
		throw GradeTooHighException();
	if (toSign > 150 || toExecute > 150)
		throw GradeTooLowException();
	_toSign = toSign;
	_toExecute = toExecute;
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

void	Form::beSigned( Bureaucrat src )
{
	if (src.getGrade() > _toSign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream & operator<<( std::ostream & out, Form const & src)
{
	out << "Form " << src.getName();
	out << " is " << (src.getSigned() ? "signed. " : "not signed. ");
	out << "You need grade " << src.getToSign() << " to sign it and ";
	out << src.getToExecute() << " to execute it."  << std::endl;
	return out;
}
