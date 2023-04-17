/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:46:45 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 19:17:05 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal( void );
	WrongAnimal( WrongAnimal const & );
	virtual ~WrongAnimal();
	
	WrongAnimal & operator=( WrongAnimal const & );
	std::string	getType( void ) const;
	void		setType( std::string );
	void		makeSound( void ) const;
};




#endif // !WRONGANIMAL_HPP