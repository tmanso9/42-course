/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:45:24 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 18:53:25 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include "AMateria.hpp"

class Node
{
public:
	// Node(/* args */);
	// ~Node();
	
	AMateria	*data;
	Node		*next;
};

#endif