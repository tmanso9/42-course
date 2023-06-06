/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:38:24 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 20:22:51 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*brain;
public:
	Cat( void );
	Cat( Cat const &);
	virtual ~Cat();
	
	Cat &			operator=(Cat const &);
	virtual void	makeSound( void ) const;
	Brain &			getBrain( void ) const;
};



#endif