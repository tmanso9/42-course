
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

void	PhoneBook::AddContact(void)
{
	std::cout << "Adding contact" << std::endl;
	std::cout << "Instance number: " << this->index << std::endl;
	this->contacts[index].addContact("ola", "ola2", "ola3", "ola4", "segredo");
	this->index++;
}

void	PhoneBook::PrintContact(int i) {
	std::cout << "Printing contact "  << i <<std::endl;
	this->contacts[i].printInfo();
}

int PhoneBook::index = 0;