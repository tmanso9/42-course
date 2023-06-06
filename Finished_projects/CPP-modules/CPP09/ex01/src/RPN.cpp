/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:51:34 by touteiro          #+#    #+#             */
/*   Updated: 2023/06/06 20:46:43 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<float>		RPN::_operands;
std::string				RPN::_tokens = "+-*/";

RPN::RPN( void )
{
}

RPN::RPN( RPN const & src )
{
	(void)src;
}

RPN & RPN::operator=( RPN const & src )
{
	(void)src;
	return *this;
}

RPN::~RPN()
{
}

void RPN::calc( std::string input )
{

	checkErrs(input);
	
	std::stringstream	ss(input);
	std::string word;

	while ( ss >> word ) {
		if ((input.find_first_of("0123456789") == std::string::npos || \
		(input.find_first_of("0123456789") != std::string::npos && input.find_first_of("*/") == 0)) && word.size() > 1) {
			errOut(", invalid token");
		} else if (_tokens.find(word) != std::string::npos ) {
			doOp(word);
		}  else {
			_operands.push(strtof(word.c_str(), NULL));
		}
	}
	if (_operands.empty() || _operands.size() > 1) {
		errOut(", invalid format");
	}
	
	std::cout << _operands.top() << std::endl;
}

void RPN::checkErrs( std::string input )
{
	if (input.empty()) {
		errOut("");
	}
	if (input.find_first_not_of("0123456789+-/* ") != std::string::npos) {
		errOut(", invalid token");
	}
	if (input.find_first_of("+-*/") == std::string::npos) {
		errOut(", missing operators");
	}
}

void RPN::doOp( std::string op ) {

	if (_operands.size() < 2) {
		errOut(", invalid format");
	}
	float modifier = _operands.top();
	_operands.pop();
	float original = _operands.top();
	_operands.pop();
	_operands.push(ops[_tokens.find(op)](original, modifier));
}

float RPN::add( float original, float n )
{
	return (original += n);
}

float RPN::subtract( float original, float n )
{
	return (original -= n);
}

float RPN::multiply( float original, float n )
{
	return (original *= n);
}

float RPN::divide( float original, float n )
{
	if (n == 0) {
		errOut(", cannot divide by 0.");
	}
	return (original /= n);
}

void RPN::errOut( std::string msg )
{
	std::cerr << "Error" << msg << std::endl;
	exit(2) ;
}

float					(*RPN::ops[4])( float, float ) = {
	&RPN::add,
	&RPN::subtract,
	&RPN::multiply,
	&RPN::divide
};