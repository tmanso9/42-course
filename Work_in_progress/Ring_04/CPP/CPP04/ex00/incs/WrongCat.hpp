/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:06:17 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 19:18:10 by touteiro         ###   ########.fr       */
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
};


#endif // !WRONGCAT_HPP
