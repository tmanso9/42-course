/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:09:25 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/22 14:44:42 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	PresidentialPardonForm( void );
	std::string	_target;

protected:
	virtual void	doSpecific ( void ) const;
	
public:
	PresidentialPardonForm( PresidentialPardonForm const &);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm &	operator=( PresidentialPardonForm const & );
	PresidentialPardonForm( std::string target);

	std::string		getTarget( void ) const;
};

#endif // !PRESIDENTIALPARDONFORM_HPP