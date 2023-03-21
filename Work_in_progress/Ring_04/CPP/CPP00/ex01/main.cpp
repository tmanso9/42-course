
#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
#include <iostream>
#include <cstring>

int	main(void)
{
	PhoneBook	book;
	std::string str;
	int			i = 7;

	while (1)
	{
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, str))
			break ;
		str = removeSpaces(str);
		if (str.size() > 10)
		{
			str.resize(10);
			str[9] = '.';
		}
		// str.shrink_to_fit();
		// std::cout << "You entered: '" << str << "'" << std::endl;
		if (!str.find("ADD") && str.size() == 3)
		{
			int	replace = book.ChangeIndex(i);
			LOG(replace);
			if (replace > 0)
				i = 0;
			else if (replace < 0)
				continue ;
			book.AddContact(i);
			i++;
		}
		else if (!str.find("SEARCH") && str.size() == 6)
		{
			std::string	str;
			LOG("What index do you want to display? Input a number from 0 to 7");
			if (!std::getline(std::cin, str))
				break ;
			int	index;
			std::istringstream(str) >> index;
			LOG(index);
			book.PrintContact(0);
		}
		else if (str == "EXIT")
			break ;
		else
			LOG("Invalid command!");
	}
}