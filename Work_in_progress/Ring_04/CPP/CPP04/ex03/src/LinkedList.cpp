/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:43:59 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/15 00:22:03 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LinkedList.hpp"


LinkedList::LinkedList() : head(NULL)
{
	return ;
}

LinkedList::LinkedList( LinkedList const & src )
{
	*this = src;
}

LinkedList & LinkedList::operator=( LinkedList const & src )
{
	Node	*curr = head;
	while (curr)
	{
		Node	*nextNode = curr->getNext();
		delete curr;
		curr = nextNode;
	}
	
	curr = src.head;
	Node	**destNode = &head;
	while (curr)
	{
		*destNode = new Node(*curr);
		curr = curr->getNext();
		Node	*nextNode = (*destNode)->getNext();
		destNode = &nextNode;
	}
	return *this;
}

LinkedList::~LinkedList()
{
	while (head)
	{
		Node	*curr = head;
		head = head->getNext();
		delete curr;
	}
}

void	LinkedList::add( AMateria *src )
{
	Node	*newNode = new Node;
	newNode->setData(src);
	newNode->setNext(NULL);

	if (!head) {
		head = newNode;
	} else {
		Node *curr = head;
		while (curr->getNext())
			curr = curr->getNext();
		curr->setNext(newNode);
	}
}