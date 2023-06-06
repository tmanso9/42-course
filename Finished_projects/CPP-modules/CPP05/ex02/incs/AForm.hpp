/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:50:12 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/22 14:44:21 by touteiro         ###   ########.fr       */
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
	const std::string	_name;
	bool				_signed;
	const int			_toSign;
	const int			_toExecute;
	AForm( void );

protected:
	AForm( std::string, int, int);
	AForm( AForm const &);
	AForm & operator=( AForm const & );
	virtual void		doSpecific ( ) const = 0;
	
public:
	virtual ~AForm();
	virtual bool			getSigned( void ) const;
	virtual std::string		getName( void ) const;
	virtual int				getToSign( void ) const;
	virtual int				getToExecute( void ) const;
	
	virtual void			beSigned( Bureaucrat const & );
	void					execute ( Bureaucrat const & ) const;

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
	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream & operator<<( std::ostream &, AForm const &);

#endif // !AFORM_HPP