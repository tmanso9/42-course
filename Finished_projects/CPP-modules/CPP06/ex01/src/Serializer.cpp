/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:59:58 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/24 16:41:38 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer & Serializer::operator=( Serializer const & src )
{
	(void)src;
	return *this;
}

Serializer::Serializer( Serializer const & src )
{
	(void)src;
}

Data*	Serializer::deserialize( uintptr_t raw )
{
	return reinterpret_cast<Data *>(raw);
}

uintptr_t	Serializer::serialize( Data* ptr )
{
	return reinterpret_cast<uintptr_t>(ptr);
}