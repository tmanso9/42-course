/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:50:12 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/17 19:24:15 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
private:
	std::string			_name;
	bool				_signed;
	int					_toSign;
	int					_toExecute;
	
public:
	AForm( void );
	AForm( AForm const &);
	AForm & operator=( AForm const & );
	virtual ~AForm();
	
	AForm( std::string, int, int);
	bool		getSigned( void ) const;
	std::string	getName( void ) const;
	int			getToSign( void ) const;
	int			getToExecute( void ) const;
	void		setSigned( bool );
	void		setName( std::string );
	void		setToSign( int );
	void		setToExecute( int );
	virtual void		beSigned( Bureaucrat );

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("grade is too high");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("grade is too low");
			}
	};
};

std::ostream & operator<<( std::ostream &, AForm const &);

#endif // !AFORM_HPP