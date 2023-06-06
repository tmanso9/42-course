/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:07:35 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/19 18:16:16 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;

class Intern
{
private:
	static AForm*	(Intern::*f[3])( std::string );
	AForm*			makeShrubberyCreation( std::string );
	AForm*			makeRobotomyRequest( std::string );
	AForm*			makePresidentialPardon( std::string );
	static std::string	knownForms[3];
	Intern & operator=( Intern const & );
	Intern( Intern const & );

public:
	Intern( void );
	~Intern();
	
	AForm*	makeForm( std::string, std::string );
};




#endif