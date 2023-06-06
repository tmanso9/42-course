/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:09:06 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/18 17:59:33 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
	:
		AForm("RobotomyRequestForm", 72, 54),
		_target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	:
		AForm("RobotomyRequestForm", 72, 54),
		_target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src)
	:
		AForm("RobotomyRequestForm", 72, 54),
		_target(src.getTarget())
{
}

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & src )
{
	this->_target = src.getTarget();
	return *this;
}

std::string		RobotomyRequestForm::getTarget( void ) const
{
	return _target;
}

void	RobotomyRequestForm::doSpecific ( void ) const
{
	std::string	outcomes[2] = \
				{" has been robotomized.", "'s robotomy has failed."};

	std::cout << "**drill drill**" << std::endl;
	std::cout << _target << outcomes[result++ % 2] << std::endl;
}

int RobotomyRequestForm::result = 0;