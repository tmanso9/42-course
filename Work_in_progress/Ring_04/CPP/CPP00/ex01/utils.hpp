
#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
#include <iostream>

# define LOG(x) std::cout << x << std::endl

std::string	removeSpaces(std::string str);
std::string	getStringFromInput(std::string str, std::string prompt);
int	allDigits(std::string phone);

#endif