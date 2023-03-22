
#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>

int	main(void)
{
	PhoneBook	book;
	std::string str;
	int			i = 0;

	while (1)
	{
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, str))
			break ;
		str = removeSpaces(str);
		
		// std::cout << "You entered: '" << str << "'" << std::endl;
		if (!str.find("ADD") && str.size() == 3)
		{
			int	replace = book.ChangeIndex(i);
			if (replace > 0)
				i = 0;
			else if (replace < 0)
				continue ;
			book.AddContact(i);
			i++;
		}
		else if (!str.find("SEARCH") && str.size() == 6)
		{
			if (!book.PrintList())
			{
				LOG("List is empty!");
				continue ;
			}
			std::string	str;
			LOG("What index do you want to display? Input one of the numbers listed");
			int	index = -1;
			int interrupt = 0;
			while (str.empty() && !interrupt)
			{
				while (str.empty() || !std::isdigit(str[0]))
				{
					if (!std::getline(std::cin, str))
					{
						interrupt = 1;
						break ;
					}
					if (!interrupt)
					{
						str = removeSpaces(str);
						if (std::isdigit(str[0]))
							break ;
						LOG("Must be a digit.");
					}
				}
				if (!interrupt)
				{
					//Need to review atoi usage
					index = atoi(str.c_str());
					if (!book.PrintContact(index))
						str.clear();
				}
			}
		}
		else if (str == "EXIT")
			break ;
		else
			LOG("Invalid command!");
	}
}