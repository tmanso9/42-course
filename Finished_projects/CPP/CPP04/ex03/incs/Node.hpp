/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:45:24 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/15 00:24:09 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include "AMateria.hpp"

class Node
{
private:
	AMateria	*data;
	Node		*next;
public:
	Node( void );
	Node( Node const & );
	~Node();
	Node & operator=( Node const & );
	
	void		setData( AMateria* );
	AMateria*	getData( void ) const;
	void		setNext( Node* );
	Node*		getNext ( void ) const;
};

#endif