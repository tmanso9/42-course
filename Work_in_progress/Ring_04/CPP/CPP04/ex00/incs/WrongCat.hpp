/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:06:17 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/17 14:10:39 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat( void );
	WrongCat( WrongCat const & );
	virtual ~WrongCat();
	
	WrongCat & operator=( WrongCat const & );
	void		makeSound( void ) const;
};


#endif // !WRONGCAT_HPP
