/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:09:06 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/22 14:44:36 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
	:
		AForm("PresidentialPardonForm", 25, 5),
		_target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
	:
		AForm("PresidentialPardonForm", 25, 5),
		_target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src)
	:
		AForm("PresidentialPardonForm", 25, 5),
		_target(src.getTarget())
{
}

PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & src )
{
	this->_target = src.getTarget();
	return *this;
}

std::string		PresidentialPardonForm::getTarget( void ) const
{
	return _target;
}

void	PresidentialPardonForm::doSpecific ( void ) const
{
	std::cout << "Zaphod Beeblebrox pardoned " << _target << std::endl;
}
