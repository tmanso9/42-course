/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:09:15 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/17 19:25:24 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm( void )
	:
		_name("default"),
		_signed(false),
		_toSign(1),
		_toExecute(1)
{
	// LOG("Form void constructor called");
}

AForm::AForm( AForm const & src)
	:
		_name(src.getName()),
		_signed(src.getSigned()),
		_toSign(src.getToSign()),
		_toExecute(src.getToExecute())
{
	// LOG("Form copy constructor called");
}

AForm & AForm::operator=( AForm const & src )
{
	this->_name = src.getName();
	this->_signed = src.getSigned();
	this->_toSign = src.getToSign();
	this->_toExecute = src.getToExecute();

	return *this;
}

AForm::~AForm()
{
	// std::cout << "Destructor called for " << _name << " form" << std::endl;
}

AForm::AForm( std::string name, int toSign, int toExecute )
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

std::string	AForm::getName( void ) const
{
	return _name;
}

bool	AForm::getSigned( void ) const
{
	return _signed;
}

int	AForm::getToSign( void ) const
{
	return _toSign;
}

int	AForm::getToExecute( void ) const
{
	return _toExecute;
}

void	AForm::setSigned( bool isSigned )
{
	_signed = isSigned;
}

void	AForm::setName( std::string name )
{
	_name = name;
}

void	AForm::setToSign( int toSign )
{
	_toSign = toSign;
}

void	AForm::setToExecute( int toExecute )
{
	_toExecute = toExecute;
}

void	AForm::beSigned( Bureaucrat src )
{
	if (src.getGrade() > _toSign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream & operator<<( std::ostream & out, AForm const & src)
{
	out << "Form " << src.getName();
	out << " is " << (src.getSigned() ? "signed. " : "not signed. ");
	out << "You need grade " << src.getToSign() << " to sign it and ";
	out << src.getToExecute() << " to execute it."  << std::endl;
	return out;
}
