
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

	int		ChangeIndex(int i);
	void	AddContact(int i);
	int		PrintList(void);
	int		PrintContact(int i);
};

#endif