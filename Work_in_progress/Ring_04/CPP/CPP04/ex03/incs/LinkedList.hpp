/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:42:51 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 18:50:58 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_HPP
# define LINKEDLIST_HPP

# include "Node.hpp"

class LinkedList
{
private:
	Node *head;
public:
	LinkedList(/* args */);
	~LinkedList();
	
	void	add(AMateria*);
};

#endif