
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
	this->index = index;
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone = phone;
	this->secret = secret;
}

int	Contact::CheckIfEmpty(void)
{
	if (this->first_name.empty())
		return (1);
	return (0);
}

void	Contact::PrintPublicInfo(void)
{
	// std::cout << std::setw(10);
	std::cout << std::setw(10) << this->index << " | ";
	
	if (this->first_name.size() > 9)
		std::cout << this->first_name.substr(0, 9) << "." << " | ";
	else
		std::cout << std::setw(10) << this->first_name << " | ";
	
	if (this->last_name.size() > 9)
		std::cout << this->last_name.substr(0, 9) << "." << " | ";
	else
		std::cout << std::setw(10) << this->last_name << " | ";
	
	if (this->nickname.size() > 9)
		std::cout << this->nickname.substr(0, 9) << "." << std::endl;
	else
		std::cout << std::setw(10) << this->nickname << std::endl;
}

void	Contact::PrintPrivateInfo(void)
{
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: "<< this->nickname << std::endl;
	std::cout << "Phone number: "<< this->phone << std::endl;
	std::cout << "Deepest secret: "<< this->secret << std::endl;
}