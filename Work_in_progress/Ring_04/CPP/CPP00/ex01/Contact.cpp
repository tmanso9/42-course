
#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructor called" << std::endl;
	
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
}

void	Contact::addContact(int index, std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret)
{
	this->_index = index;
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
	// std::cout << std::setw(10);
	std::cout << std::setw(10) << this->_index << " | ";
	
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