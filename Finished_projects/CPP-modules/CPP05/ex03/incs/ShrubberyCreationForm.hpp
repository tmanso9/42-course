/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:09:25 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/18 16:17:28 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;
	ShrubberyCreationForm( void );
protected:
	virtual void	doSpecific ( void ) const;

public:
	ShrubberyCreationForm( ShrubberyCreationForm const &);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & );
	ShrubberyCreationForm( std::string target);

	std::string		getTarget( void ) const;

	class FileNotCreatedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif // !ShrubberyCreationForm_HPP