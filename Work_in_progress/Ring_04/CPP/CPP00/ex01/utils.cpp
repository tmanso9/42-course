
#include "utils.hpp"

std::string	removeSpaces(std::string str)
{
	while (std::isspace(str[0]))
		str.erase(0, 1);
	while (std::isspace(str[str.size() - 1]))
		str.erase(str.size() - 1, 1);
	return (str);
}

