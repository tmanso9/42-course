/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:21:03 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/06 16:58:38 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iomanip>
# include <iostream>

# define LOG(x) std::cout << x << std::endl

class Contact
{
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone;
	std::string	_secret;
public:
	Contact(void);
	~Contact(void);

	int	index;

	void	CreateContact(int i, std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret);
	void	PrintPrivateInfo(void);
	void	PrintPublicInfo(void);
	int		CheckIfEmpty(void);
};

#endif