/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:43:59 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 18:52:45 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LinkedList.hpp"


LinkedList::LinkedList() : head(NULL)
{
	return ;
}

LinkedList::~LinkedList()
{
	while (head)
	{
		Node	*cur = head;
		head = head->next;
		delete cur->data;
		delete cur;
	}
}

void	LinkedList::add( AMateria *src)
{
	Node	*newNode = new Node;
	newNode->data = src;
	newNode->next = NULL;

	if (!head) {
		head = newNode;
	} else {
		Node *curr = head;
		while (curr->next)
			curr = curr->next;
		curr->next = newNode;
	}
}