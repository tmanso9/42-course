/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:10:31 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/17 19:02:54 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>
# include <exception>

# define LOG(x) std::cout << x << std::endl;

class AForm;

class Bureaucrat
{
private:
	std::string	_name;
	int			_grade;
public:
	Bureaucrat( void );
	Bureaucrat( Bureaucrat const & );
	Bureaucrat & operator=( Bureaucrat const & );
	~Bureaucrat();
	
	Bureaucrat( std::string, int );
	
	std::string	getName(void) const;
	int			getGrade(void) const;
	void		incrementGrade(void);
	void		decrementGrade(void);
	void		signForm( AForm & );

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

std::ostream &	operator<<(std::ostream &, Bureaucrat const & );

#endif