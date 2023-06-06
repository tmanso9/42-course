/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:07:03 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/25 17:21:33 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl constructor called" << std::endl;
	this->_levels[0] = "DEBUG";
	this->_levels[1] = "INFO";
	this->_levels[2] = "WARNING";
	this->_levels[3] = "ERROR";
}

Harl::~Harl()
{
	std::cout << "Harl destructor called" << std::endl;
}

void	Harl::complain(std::string level)
{
	int num = -1;
	for (int i = 0; i < 4; i++)
	{
		if (this->_levels[i] == level)
		{
			num = i;
			break ;
		}
	}

	/*
	The fallthrough attribute with a null statement serves as a fallthrough statement.
	It hints to the compiler that a statement that falls through to another case label,
	or user-defined label in a switch statement is intentional
	and thus the -Wimplicit-fallthrough warning must not trigger.
	*/
	switch (num)
	{
	case 0:
		std::cout << "[DEBUG]" << std::endl;
		this->_debug();
		__attribute__((fallthrough));
	case 1:
		std::cout << "[INFO]" << std::endl;
		this->_info();
		__attribute__((fallthrough));
	case 2:
		std::cout << "[WARNING]" << std::endl;
		this->_warning();
		__attribute__((fallthrough));
	case 3:
		std::cout << "[ERROR]" << std::endl;
		this->_error();
		break;
	
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
	}
	
	
}

void	Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}