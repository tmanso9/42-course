/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:09:06 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/17 19:29:30 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
{
	_target = "/";
	this->setSigned(false);
	this->setName("Presidential pardon");
	this->setToSign(1);
	this->setToExecute(1);
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
{
	_target = target;
	this->setSigned(false);
	this->setName("Presidential pardon");
	this->setToSign(25);
	this->setToExecute(5);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}