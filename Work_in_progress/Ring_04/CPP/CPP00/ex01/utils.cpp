
#include "utils.hpp"

std::string	removeSpaces(std::string str)
{
	while (std::isspace(str[0]))
		str.erase(0, 1);
	while (std::isspace(str[str.size() - 1]))
		str.erase(str.size() - 1, 1);
	return (str);
}

std::string	getStringFromInput(std::string str, std::string prompt)
{
	std::cout << prompt;
	if (!std::getline(std::cin, str))
		return str;
	str = removeSpaces(str);
	std::cout << "You entered: '" << str << "'" << std::endl;
	while (str.empty())
	{
		LOG("Field can't be empty!");
		std::cout << prompt;
		std::getline(std::cin, str);
		removeSpaces(str);
	}
	return (str);
}