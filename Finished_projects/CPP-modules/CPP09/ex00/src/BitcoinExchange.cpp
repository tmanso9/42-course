/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:32:33 by touteiro          #+#    #+#             */
/*   Updated: 2023/06/06 20:40:49 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, float>	BitcoinExchange::_database;
std::ifstream					BitcoinExchange::_dbFile;
std::ifstream					BitcoinExchange::_convertFile;
time_t 							BitcoinExchange::_t = time(NULL);
std::string						BitcoinExchange::_date;
std::string						BitcoinExchange::_val;
float							BitcoinExchange::_floatVal;

BitcoinExchange::BitcoinExchange()
{
	LOG("Default constructor");
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src )
{
	(void)src;
	LOG("Copy constructor");
}

BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange const & src )
{
	(void)src;
	LOG("Assignment Operator");
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	LOG("Default destructor");
}

void	BitcoinExchange::convert( std::string filename )
{
	try
	{
		buildDB();
		processFile(filename);
	}
	catch ( const std::exception& e )
	{
		std::cerr << e.what() << " data.csv\n";
	}
	
	if (_dbFile.is_open()) {
		_dbFile.close();
	}
	if (_convertFile.is_open()) {
		_convertFile.close();
	}
}

void	BitcoinExchange::buildDB( void )
{
	std::ifstream _dbFile("data.csv", std::ifstream::in);
	if (!_dbFile.is_open()) {
		throw cantOpenException();
	}
	
	std::string line;
	int i = 2;
	std::getline(_dbFile, line);
	while (!_dbFile.eof()) {
		std::getline(_dbFile, line);
		if (line.empty()) {
			continue ;
		}
		std::size_t sep = line.find(',');
		std::string date = line.substr(0, sep);
		std::string val = line.substr(sep + 1);
		if ( !validDate(date) ) {
			std::cerr << "Line " << i << ": Wrong date: " << line << std::endl;
			throw invalidDBException();
		}
		if (!validValue(val)) {
			std::cerr << "Line " << i << ": Wrong value: " << line << std::endl;
			throw invalidDBException();
		}
		_database[date] = strtof(val.c_str(), NULL);
		i++;
	}
	
}

bool BitcoinExchange::validDate( std::string date )
{
	struct tm *timeptr = localtime(&_t);
	if (strptime(date.c_str(), "%Y-%m-%d", timeptr) == NULL || date.size() != 10) {
		return false;
	}
	int year = timeptr->tm_year + 1900;
	int leap = (((year % 4 == 0) && (year % 100 > 0)) || (year % 400 == 0));
	int mon = timeptr->tm_mon + 1;
	int day = timeptr->tm_mday;
	if (day == 0) {
		return false;
	}
	if ((mon == 4 || mon == 6 || mon == 9 || mon == 11) && day > 30) {
		return false;
	}
	if (mon == 2 && day > (28 + leap)) {
		return false;
	}
	return true;
}

bool BitcoinExchange::validValue( std::string val )
{
	if (val.empty() || \
	val.find_first_not_of("+-0123456789.ef") != std::string::npos || \
	val.find('+') != val.find_last_of('+') || \
	val.find('-') != val.find_last_of('-') || \
	val.find('.') != val.find_last_of('.') || \
	val.find('e') != val.find_last_of('e') || \
	(val.find('f') != std::string::npos && val.find('f') != val.size() - 1) || \
	(val.find('+') != std::string::npos && val.find('-') != std::string::npos)) {
		return false;
	}
	
	return true;
}

void BitcoinExchange::processFile( std::string filename )
{
	try
	{
		std::ifstream _convertFile(filename.c_str(), std::ifstream::in);
		if (!_convertFile.is_open()) {
			throw cantOpenException();
		}

		std::string line;
		std::getline(_convertFile, line);
		while (!_convertFile.eof()) {
			std::getline(_convertFile, line);
			if (line.empty()) {
				continue ;
			}
			try
			{
				checkLine(line);
				int exists = _database.count(_date);
				if (!exists && _database.lower_bound(_date) == _database.begin()) {
					std::cerr << "Error: " << _date << " is older than acceptable" << std::endl;
					continue ;
				}
				std::cout << _date << " => " << _val << " = " << std::setprecision(7) <<\
				( exists ? \
				_database.lower_bound(_date)->second * _floatVal: \
				(--_database.lower_bound(_date))->second * _floatVal) << \
				std::endl;
			}
			catch(const badInputException& e)
			{
				std::cerr << e.what() << " => " << line << std::endl;
			}
			catch(const numberTooBigException& e)
			{
				std::cerr << e.what() <<  '\n';
			}
			catch(const negativeNumberException& e)
			{
				std::cerr << e.what() <<  '\n';
			}
		}
	}
	catch ( const std::exception & e )
	{
		std::cerr << e.what() << " " << filename << std::endl;
	}
	
	
}

void BitcoinExchange::checkLine( std::string line )
{
	size_t sep = line.find('|');
	if (sep == std::string::npos || sep != line.find_last_of('|')) {
		throw badInputException();
	}
	_date = line.substr(0, sep - 1);
	_val = line.substr(sep + 2);
	if (!validDate(_date) || !validValue(_val)) {
		throw badInputException();
	}
	_floatVal = strtof(_val.c_str(), NULL);
	if (_floatVal < 0) {
		throw negativeNumberException();
	}
	if (_floatVal > 1000) {
		throw numberTooBigException();
	}
}

const char* BitcoinExchange::cantOpenException::what() const throw()
{
	return "Error: cannot open";
}

const char* BitcoinExchange::invalidDBException::what() const throw()
{
	return "Error: invalid database";
}

const char* BitcoinExchange::badInputException::what() const throw()
{
	return "Error: bad input";
}

const char* BitcoinExchange::numberTooBigException::what() const throw()
{
	return "Error: too large a number.";
}

const char* BitcoinExchange::negativeNumberException::what() const throw()
{
	return "Error: not a positive number.";
}