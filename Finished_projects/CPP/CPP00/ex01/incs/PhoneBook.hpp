/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:22:04 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/06 16:58:40 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "utils.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];

	std::string		_getStringFromInput(std::string str, std::string prompt);
	int				_allDigits(std::string phone);

public:

	PhoneBook(void);
	~PhoneBook(void);

	int		ReplaceContact(int i);
	void	AddContact(int i);
	void	MoveContacts(void);
	int		PrintList(void);
	int		PrintContact(int i);
};

#endif