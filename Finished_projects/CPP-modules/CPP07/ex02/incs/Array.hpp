/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:41:41 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/26 14:03:04 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

# define LOG(x) std::cout << x << std::endl;

template<typename T>
class Array
{
private:
	T				*_arr;
	unsigned int	_size;
public:
	/* Constructors */ 
	Array<T>() : _size(0) {
		// LOG("Default array constructor called");
		_arr = new T[_size];
	};
	
	Array<T>(unsigned int n) : _size(n) {
		// LOG("Sized array constructor called");
		_arr = new T[n];
	}

	Array<T>( const Array & src ) : _size(src.size()) {
		// LOG("Array copy constructor called");
		_arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_arr[i] = src[i];
		}
	}
	
	/* Destructor */
	~Array() {
		// LOG("Array destructor called");
		delete [] _arr;
	};

	/* Operators */
	Array<T> & operator=( const Array & src ) {
		// LOG("Array assignment operator called");
		if (this != &src) {
			delete [] _arr;
			_size = src.size();
			_arr = new T[_size];
			for (unsigned int i = 0; i < _size; i++) {
				_arr[i] = src[i];
			}
		}
		return *this;
	}
	
	T & operator[]( int n ){
		if (n < 0 || n >= static_cast<int>(_size)) {
			throw outOfBoundsException();
		}
		return _arr[n];
	}

	T & operator[]( int n ) const{
		if (n < 0 || n >= static_cast<int>(_size)) {
			throw outOfBoundsException();
		}
		return _arr[n];
	}

	unsigned int size() const {
		return _size;
	}

	/* Exceptions */
	class outOfBoundsException : public std::exception{
		public:
			virtual const char* what() const throw() { return "Out of bounds"; };
	};
};

#endif