/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:28:47 by touteiro          #+#    #+#             */
/*   Updated: 2023/06/05 14:20:31 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <string>
# include <cstdlib>
# include <exception>
# include <time.h>
# include <map>

# define LOG(x) std::cout << x << std::endl;

class BitcoinExchange
{
private:
	BitcoinExchange( void );
	BitcoinExchange( BitcoinExchange const & );
	BitcoinExchange & operator=( BitcoinExchange const & );
	
	static std::map<std::string, float>	_database;
	static std::ifstream				_dbFile;
	static std::ifstream				_convertFile;
	static time_t						_t;
	static std::string					_date;
	static std::string					_val;
	static float						_floatVal;

	static void	buildDB( void );
	static void processFile( std::string );
	
	static bool validDate( std::string );
	static bool validValue( std::string );
	static void checkLine( std::string );
public:
	~BitcoinExchange();
	static void	convert( std::string );
	
	class badInputException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
	class numberTooBigException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
	class negativeNumberException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
	class cantOpenException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
	class invalidDBException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
	
};

#endif // !BITCOINEXCHANGE_HPP