
#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called" << std::endl;
}

void	PhoneBook::AddContact(int i)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone;
	std::string	secret;
	
	first_name = getStringFromInput(first_name, "First name: ");
	last_name = getStringFromInput(last_name, "Last name: ");
	nickname = getStringFromInput(nickname, "Nickname: ");
	phone = getStringFromInput(phone, "Phone number: ");
	while (!allDigits(phone))
		phone = getStringFromInput(phone, "Phone number: ");
	secret = getStringFromInput(secret, "Deepest darkest secret: ");

	this->contacts[i].addContact(i, first_name, last_name, nickname, phone, secret);
}

int	PhoneBook::PrintList(void) {
	int allEmpty = 1;
	for (int i = 0; i < 8; i++)
		if (!this->contacts[i].CheckIfEmpty())
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
		if (!this->contacts[i].CheckIfEmpty())
			this->contacts[i].PrintPublicInfo();
	}
	return (1);
}

int	PhoneBook::PrintContact(int i) {
	if (i < 0 || i > 7 || this->contacts[i].CheckIfEmpty())
	{
		LOG("Index out of range. Try again");
		return (0);
	}
	else
		this->contacts[i].PrintPrivateInfo();
	return (1);
}

int		PhoneBook::ChangeIndex(int i)
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
			if ((!str.find("y") || !str.find("Y")) && str.size() == 1)
				return (1);
			else if ((!str.find("n") || !str.find("N")) && str.size() == 1)
				return (-1);
			else
				LOG("Invalid option. Enter only y/n");
		}
	}
	return (0);
}

int	PhoneBook::allDigits(std::string phone)
{
	if (!phone.size())
		return (0);
	for (int i = 0; i < (int)phone.size(); i++)
	{
		if (!std::isdigit(phone[i]))
		{
			std::cout << "Number must be only digits" << std::endl;
			return (0);
		}
	}
	return (1);
}

std::string	PhoneBook::getStringFromInput(std::string str, std::string prompt)
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
