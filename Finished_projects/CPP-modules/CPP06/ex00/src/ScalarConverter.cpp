/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:43:26 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/24 13:26:46 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

float	ScalarConverter::toFloat;
double	ScalarConverter::toDouble;
char	ScalarConverter::toChar;
int		ScalarConverter::toInt;

ScalarConverter::ScalarConverter( void )
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const & src)
{
	(void)src;
	std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter & ScalarConverter::operator=( ScalarConverter const & src )
{
	(void)src;
	std::cout << "ScalarConverter assignment overload called" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

void ScalarConverter::convert( std::string toConvert )
{
	if (toConvert.empty() || \
		toConvert.find('-') != toConvert.find_last_of('-') || \
		toConvert.find('+') != toConvert.find_last_of('+') || \
		toConvert.find('.') != toConvert.find_last_of('.') || \
		toConvert.find('e') != toConvert.find_last_of('e') || \
		(toConvert.find('+') != std::string::npos && toConvert.find('-') != std::string::npos)) {
		impossiblePrint(true);
	}
	else if (toConvert.size() == 1 && !isdigit(*toConvert.begin())) {
		printResult(*toConvert.begin());
	}
	else if (toConvert.find_first_not_of("0123456789-+") == std::string::npos) {
		printResult(std::atoi(toConvert.c_str()));
	}
	else if (toConvert.find_first_of(".e") != std::string::npos && validFormat(toConvert)) {
		if (toConvert.find('f') == std::string::npos) {
			printResult((std::atof(toConvert.c_str())));
		} else if (toConvert.find('f') == toConvert.size() - 1) {
			printResult(static_cast<float>(std::atof(toConvert.c_str())));
		} else {
			impossiblePrint(true);
		}
	}
	else if ((toConvert.find("inf") != std::string::npos || toConvert.find("nan") != std::string::npos) && \
				isLimit(toConvert)) {
		if ((toConvert.find('f') == toConvert.size() - 1 && toConvert.find("nan") == std::string::npos) || \
			!toConvert.compare("nan")) {
			printResult((std::atof(toConvert.c_str())));
		} else {
			printResult(static_cast<float>(std::atof(toConvert.c_str())));
		}
	}
	else {
		impossiblePrint(true);
	}
}

bool		ScalarConverter::validFormat( std::string toConvert )
{
	bool	valid = true;
	size_t	pos;
	
	if (toConvert.find_first_not_of("0123456789.ef-+") != std::string::npos) {
		valid = false;
	}
	
	pos = toConvert.find_first_of(".e");
	while (pos != std::string::npos && valid == true) {
		char nextChar = *(toConvert.c_str() + pos + 1);
		if (!std::isdigit(nextChar) && nextChar != '+' && nextChar != '-') {
			valid = false;
		}
		pos = toConvert.find_first_of(".e", pos + 1);
	}
	
	return valid;
}

bool	ScalarConverter::isLimit( std::string toConvert )
{
	std::string	Limits[8] = {"inf", "+inf", "-inf", "inff", "+inff", "-inff", "nan", "nanf"};
	
	for (int i = 0; i < 8; i++) {
		if (!toConvert.compare(Limits[i].c_str())) {
			return true;
		}
	}
	
	return false;
}

void	ScalarConverter::printResult( char c )
{
	LOG("\nDetected a char\n");

	toChar = c;
	toInt = static_cast<int>( c );
	toFloat = static_cast<float>( c );
	toDouble = static_cast<double>( c );
	
	if (isprint(toChar)) {
		std::cout << "char:\t'" << toChar <<"'" << std::endl;
	} else {
		std::cout << "char:\t" << "Non displayable" << std::endl;
	}
	std::cout << "int:\t" << toInt << std::endl;
	std::cout << "float:\t" << toFloat << ".0f" << std::endl;
	std::cout << "double:\t" << toDouble << ".0" << std::endl;
}

void	ScalarConverter::printResult( int i )
{
	LOG("\nDetected an int\n");
	
	toChar = static_cast<char>( i );
	toInt = i;
	toFloat = static_cast<float>( i );
	toDouble = static_cast<double>( i );
	
	if (isprint(toChar)) {
		std::cout << "char:\t'" << toChar <<"'" << std::endl;
	} else {
		std::cout << "char:\t" << "Non displayable" << std::endl;
	}
	std::cout << "int:\t" << toInt << std::endl;
	std::cout << "float:\t" << toFloat << ".0f" << std::endl;
	std::cout << "double:\t" << toDouble << ".0" << std::endl;
}

void	ScalarConverter::printResult( double d )
{
	LOG("\nDetected a double\n");
	
	if (std::isnan(d)) {
		impossiblePrint(false);
		return ;
	}
	
	toChar = static_cast<char>( d );
	toInt = static_cast<int>( d );
	toFloat = static_cast<double>( d );
	toDouble = d;
	
	bool infinite = std::isinf(toDouble) || \
					toDouble < std::numeric_limits<int>::min() || \
					toDouble > std::numeric_limits<int>::max();
		
	if (isprint(toChar)) {
		std::cout << "char:\t'" << toChar <<"'" << std::endl;
	} else if (infinite) {
		std::cout << "char:\t" << "impossible" << std::endl;
	} 
	else {
		std::cout << "char:\t" << "Non displayable" << std::endl;
	}
	if (infinite) {
		std::cout << "int:\t" << "impossible" << std::endl;
	} else {
		std::cout << "int:\t" << toInt << std::endl;
	}
	std::cout << "float:\t" << toFloat << (toDouble - toInt == 0 ? ".0f" : "f") << std::endl;
	std::cout << "double:\t" << toDouble << (toDouble - toInt == 0 ? ".0" : "") << std::endl;
}

void	ScalarConverter::printResult( float f )
{
	LOG("\nDetected a float\n");
	
	if (std::isnan(f)) {
		impossiblePrint(false);
		return ;
	}
	
	toChar = static_cast<char>( f );
	toInt = static_cast<int>( f );
	toFloat = f;
	toDouble = static_cast<double>( f );
	
	bool infinite = std::isinf(toFloat) || \
					toFloat < std::numeric_limits<int>::min() || \
					toFloat > std::numeric_limits<int>::max();;
	
	if (isprint(toChar)) {
		std::cout << "char:\t'" << toChar <<"'" << std::endl;
	} else if (infinite) {
		std::cout << "char:\t" << "impossible" << std::endl;
	} 
	else {
		std::cout << "char:\t" << "Non displayable" << std::endl;
	}
	if (infinite) {
		std::cout << "int:\t" << "impossible" << std::endl;
	} else {
		std::cout << "int:\t" << toInt << std::endl;
	}
	std::cout << "float:\t" << toFloat << (toFloat - toInt == 0 ? ".0f" : "f") << std::endl;
	std::cout << "double:\t" << toDouble << (toFloat - toInt == 0 ? ".0" : "") << std::endl;
}

void	ScalarConverter::impossiblePrint( bool error )
{
	if (error) {
		LOG("\nDetected invalid type\n");
	}
	
	std::cout << "char:\t" << "impossible" << std::endl;
	std::cout << "int:\t" << "impossible" << std::endl;
	std::cout << "float:\t" << (error ? "impossible" : "nanf") << std::endl;
	std::cout << "double:\t" << (error ? "impossible" : "nan") << std::endl;
}
