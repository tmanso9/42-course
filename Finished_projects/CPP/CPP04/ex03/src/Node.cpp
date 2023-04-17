/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:58:28 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/15 00:10:09 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Node.hpp"

Node::Node()
{
	return ;
}

Node::Node( Node const & src)
{
	data = src.data->clone();
	next = src.next;
}

Node & Node::operator=( Node const & src )
{
	delete data;
	data = src.data->clone();
	next = src.next;

	return *this;
}

Node::~Node( void )
{
	delete data;
}

void	Node::setData( AMateria *newData )
{
	data = newData;
}

AMateria	*Node::getData( void ) const
{
	return data;
}

void	Node::setNext( Node * newNext )
{
	next = newNext;
}

Node	*Node::getNext( void ) const
{
	return next;
}