/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:21:28 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/22 19:35:01 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

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
		if (!str.compare("ADD"))
		{
			int	replace = book.ReplaceContact(i);
			if (replace < 0)
				continue ;
			else if (replace > 0)
			{
				book.MoveContacts();
				i = 7;
			}
			book.AddContact(i);
			i++;
		}
		else if (!str.compare("SEARCH"))
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
				while (str.empty() || !std::isdigit(*str.begin()))
				{
					if (!std::getline(std::cin, str))
					{
						interrupt = 1;
						break ;
					}
					if (!interrupt)
					{
						str = removeSpaces(str);
						if (std::isdigit(*str.begin()))
							break ;
						LOG("Must be a digit.");
					}
				}
				if (!interrupt)
				{
					index = std::atoi(str.c_str());
					if (!book.PrintContact(index))
						str.clear();
				}
			}
		}
		else if (!str.compare("EXIT"))
			break ;
		else
			LOG("Invalid command!");
	}
}
