/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:50:12 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/19 17:21:58 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_toSign;
	const int			_toExecute;
	Form( void );
	
public:
	Form( Form const &);
	Form & operator=( Form const & );
	~Form();
	
	Form( std::string, int, int);
	
	std::string	getName( void ) const;
	bool		getSigned( void ) const;
	int			getToSign( void ) const;
	int			getToExecute( void ) const;
	
	void		beSigned( Bureaucrat const & );

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream & operator<<( std::ostream &, Form const &);

#endif // !FORM_HPP