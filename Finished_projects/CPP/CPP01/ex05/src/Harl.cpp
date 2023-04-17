/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:07:03 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/10 20:21:25 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "\033[0;32mHarl constructor called\033[0m" << std::endl;
	this->_levels[0] = "DEBUG";
	this->_levels[1] = "INFO";
	this->_levels[2] = "WARNING";
	this->_levels[3] = "ERROR";
}

Harl::~Harl()
{
	std::cout << "\033[0;31mHarl destructor called\033[0m" << std::endl;
}

void	Harl::complain(std::string level)
{

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
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}