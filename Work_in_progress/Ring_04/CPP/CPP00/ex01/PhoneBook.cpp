
#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	// std::cout << "PhoneBook constructor called" << std::endl;
	LOG("PhoneBook constructor called");

	
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
	secret = getStringFromInput(secret, "Deepest darkest secret: ");

	this->contacts[i].addContact(first_name, last_name, nickname, phone, secret);
}

void	PhoneBook::PrintContact(int i) {
	std::cout << "Printing contact "  << i <<std::endl;
	this->contacts[i].printInfo();
}

int		PhoneBook::ChangeIndex(int i)
{
	std::string	str;
	if (i > 7)
	{
		LOG("You can have a maximum of 8 contacts!");
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

int PhoneBook::index = 0;