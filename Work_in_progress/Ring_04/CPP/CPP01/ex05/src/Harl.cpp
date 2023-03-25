/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:07:03 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/25 16:33:46 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl constructor called" << std::endl;
	this->_levels[0] = "debug";
	this->_levels[1] = "info";
	this->_levels[2] = "warning";
	this->_levels[3] = "error";
}

Harl::~Harl()
{
	std::cout << "Harl destructor called" << std::endl;
}

void	Harl::complain(std::string level)
{
	/* switch (std::atoi(level.c_str()))
	{
	case 0:
		this->_debug();
		break;
	case 1:
		this->_info();
		break;
	case 2:
		this->_warning();
		break;
	case 3:
		this->_error();
		break ;
	
	default:
		std::cout << "Wrong option!" << std::endl;
		break;
	} */

	void	(Harl::*functions[4]) (void);
	functions[0] = &Harl::_debug;
	functions[1] = &Harl::_info;
	functions[2] = &Harl::_warning;
	functions[3] = &Harl::_error;
	
	for (int i = 0; i < 4; i++)
	{
		if (this->_levels[i] == level)
		{
			(this->*functions[i])();
			return ;
		}
	}	
	std::cout << "Wrong option! Give me a better one." << std::endl;
	
}

void	Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}