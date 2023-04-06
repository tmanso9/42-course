/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:21:50 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/06 15:28:59 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "\033[0;32mPhoneBook constructor called\033[0m" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "\033[0;31mPhoneBook destructor called\033[0m" << std::endl;
}

void	PhoneBook::AddContact(int i)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone;
	std::string	secret;
	
	first_name = _getStringFromInput(first_name, "First name: ");
	last_name = _getStringFromInput(last_name, "Last name: ");
	nickname = _getStringFromInput(nickname, "Nickname: ");
	phone = _getStringFromInput(phone, "Phone number: ");
	while (!_allDigits(phone))
		phone = _getStringFromInput(phone, "Phone number: ");
	secret = _getStringFromInput(secret, "Deepest darkest secret: ");

	this->_contacts[i].CreateContact(i, first_name, last_name, nickname, phone, secret);
}

void	PhoneBook::MoveContacts(void)
{
	for (int i = 1; i < 8; i++)
	{
		this->_contacts[i - 1] = this->_contacts[i];
		this->_contacts[i - 1].index = i - 1;
	}
}

int	PhoneBook::PrintList(void)
{
	int allEmpty = 1;
	for (int i = 0; i < 8; i++)
		if (!this->_contacts[i].CheckIfEmpty())
			allEmpty = 0;
	if (!allEmpty)
	{
		std::cout << std::setw(10) << "Index" << " | ";
		std::cout << std::setw(10) << "Name" << " | ";
		std::cout << std::setw(10) << "Last name" << " | ";
		std::cout << std::setw(10) << "Nickname" << std::endl;
	}
	else
		return (0);
	for (int i = 0; i < 8; i++)
	{
		if (!this->_contacts[i].CheckIfEmpty())
			this->_contacts[i].PrintPublicInfo();
	}
	return (1);
}

int	PhoneBook::PrintContact(int i)
{
	if (i < 0 || i > 7 || this->_contacts[i].CheckIfEmpty())
	{
		LOG("Index out of range. Try again");
		return (0);
	}
	else
		this->_contacts[i].PrintPrivateInfo();
	return (1);
}

int		PhoneBook::ReplaceContact(int i)
{
	std::string	str;
	if (i > 7)
	{
		LOG("You can have a maximum of 8 contacts.");
		LOG("Do you want to replace the oldest one? Y/N");
		while (1)
		{
			if (!std::getline(std::cin, str))
				return (-1);
			str = removeSpaces(str);
			if (!str.compare("y") || !str.compare("Y"))
				return (1);
			else if (!str.compare("n") || !str.compare("N"))
				return (-1);
			else
				LOG("Invalid option. Enter only y/n");
		}
	}
	return (0);
}

int	PhoneBook::_allDigits(std::string phone)
{
	if (phone.empty())
		return (0);
	for (int i = 0; i < (int)phone.size(); i++)
	{
		if (!std::isdigit(*(phone.begin() + i)))
		{
			std::cout << "Number must be only digits" << std::endl;
			return (0);
		}
	}
	return (1);
}

std::string	PhoneBook::_getStringFromInput(std::string str, std::string prompt)
{
	std::cout << prompt;
	if (!std::getline(std::cin, str))
		return str;
	str = removeSpaces(str);
	while (str.empty())
	{
		LOG("Field can't be empty!");
		std::cout << prompt;
		std::getline(std::cin, str);
		removeSpaces(str);
	}
	return (str);
}
