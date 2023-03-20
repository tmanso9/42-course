
#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructor called" << std::endl;
	
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
}

void	Contact::addContact(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone = phone;
	this->secret = secret;
}

void	Contact::printInfo(void)
{
	LOG(first_name);
	LOG(last_name);
	LOG(nickname);
	LOG(phone);
	LOG(secret);
}