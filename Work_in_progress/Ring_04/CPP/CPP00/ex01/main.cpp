
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iostream>
#include <cstring>

std::string	removeSpaces(std::string str)
{
	while (std::isspace(str[0]))
		str.erase(0, 1);
	while (std::isspace(str[str.size() - 1]))
		str.erase(str.size() - 1, 1);
	return (str);
}

int	main(void)
{
	PhoneBook	book;
	std::string str;

	while (1)
	{
		std::cout << "Enter command: ";
		std::getline (std::cin, str);
		str = removeSpaces(str);
		if (str.size() > 10)
		{
			str.resize(10);
			str[9] = '.';
		}
		// str.shrink_to_fit();
		std::cout << "You entered: '" << str << "'" << std::endl;
		if (!str.find("ADD") && str.size() == 3)
		{
			book.AddContact();
		}
		else if (str == "SEARCH")
			book.PrintContact(0);
		else if (str == "EXIT")
			break ;
	}
}