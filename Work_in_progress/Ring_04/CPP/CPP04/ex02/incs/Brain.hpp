/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:58:26 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 19:48:53 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
	std::string	ideas[100];
public:
	Brain( void );
	Brain( Brain const & );
	~Brain();
	Brain &	operator=( Brain const & );	

};


#endif