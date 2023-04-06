/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:20:40 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/06 15:26:04 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "\033[0;32mContact constructor called\033[0m" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "\033[0;31mContact destructor called\033[0m" << std::endl;
}

void	Contact::CreateContact(int index, std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret)
{
	this->index = index;
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nickname = nickname;
	this->_phone = phone;
	this->_secret = secret;
}

int	Contact::CheckIfEmpty(void)
{
	if (this->_first_name.empty())
		return (1);
	return (0);
}

void	Contact::PrintPublicInfo(void)
{
	std::cout << std::setw(10) << this->index << " | ";
	
	if (this->_first_name.size() > 9)
		std::cout << this->_first_name.substr(0, 9) << "." << " | ";
	else
		std::cout << std::setw(10) << this->_first_name << " | ";
	
	if (this->_last_name.size() > 9)
		std::cout << this->_last_name.substr(0, 9) << "." << " | ";
	else
		std::cout << std::setw(10) << this->_last_name << " | ";
	
	if (this->_nickname.size() > 9)
		std::cout << this->_nickname.substr(0, 9) << "." << std::endl;
	else
		std::cout << std::setw(10) << this->_nickname << std::endl;
}

void	Contact::PrintPrivateInfo(void)
{
	std::cout << "First name: " << this->_first_name << std::endl;
	std::cout << "Last name: " << this->_last_name << std::endl;
	std::cout << "Nickname: "<< this->_nickname << std::endl;
	std::cout << "Phone number: "<< this->_phone << std::endl;
	std::cout << "Deepest secret: "<< this->_secret << std::endl;
}
