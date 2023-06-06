/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:09:25 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/18 16:17:28 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include "AForm.hpp"
# include <stdlib.h>

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;
	RobotomyRequestForm( void );
	static int	result;

protected:
	virtual void	doSpecific ( void ) const;

public:
	RobotomyRequestForm( RobotomyRequestForm const &);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm &	operator=( RobotomyRequestForm const & );
	RobotomyRequestForm( std::string target);

	std::string		getTarget( void ) const;
};

#endif // !RobotomyRequestForm_HPP