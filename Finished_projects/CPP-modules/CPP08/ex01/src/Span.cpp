/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:22:52 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/31 16:17:19 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) : N(0)
{
}

Span::Span( unsigned int maxSize ) : N(maxSize)
{
}

Span::Span( Span const & src ) : N(src.N)
{
	*this = src;
}

Span::~Span()
{
}

Span & Span::operator=( Span const & src )
{
	if (_arr.size()) {
		_arr.clear();
	}
	N = src.N;
	_arr = src._arr;
	return *this;
}

void	Span::addNumber( int newNumber )
{
	if (_arr.size() == N) {
		throw fullArrException();
	} else {
		_arr.push_back(newNumber);
	}
}

/* 
 Fill the array with numbers in the given range
*/
void	Span::addNumber( int lowest, int highest )
{
	if (_arr.size() == N) {
		throw fullArrException();
	}
	unsigned int	inUse = _arr.size();
	int calcHi = highest - lowest + 1;
	for (unsigned int i = 0; i < N && inUse++ < N ; i++) {
		addNumber(rand() % calcHi + lowest);
	}
}

void	Span::addNumber( std::vector<int>::iterator begin, std::vector<int>::iterator end ) {
	if (_arr.size() == N) {
		throw fullArrException();
	}
	unsigned int	inUse = _arr.size();
	for (; (begin < end && inUse++ < N); begin++) {
		addNumber(*begin);
	}
}

std::vector<int> & Span::getArr( void )
{
	return _arr;
}

unsigned int	Span::shortestSpan( void )
{
	if (_arr.size() < 2) {
		throw noSpanException();
	}
	
	std::vector<int> temp = _arr;
	std::sort(temp.begin(), temp.end());
	
	std::vector<int> res;
	std::adjacent_difference(temp.begin(), temp.end(), std::back_inserter(res));
	return *(std::min_element(res.begin() + 1, res.end()));
}

unsigned int	Span::longestSpan( void )
{
	if (_arr.size() < 2) {
		throw noSpanException();
	}
	std::vector<int> tmp = _arr;
	std::sort(tmp.begin(), tmp.end());
	
	unsigned int longest;
	longest = tmp.back() - tmp.front();
	
	return longest;
}

int	Span::operator[]( unsigned int i ) const
{
	if (i >= _arr.size()) {
		throw outOfRangeException();
	}
	return _arr[i];
}

std::ostream & operator<<( std::ostream & o, Span & src ){
	std::vector<int>::iterator it = src.getArr().begin();
	for (; it != src.getArr().end(); it++) {
		std::cout << *it << " ";
	}
	return o;
}