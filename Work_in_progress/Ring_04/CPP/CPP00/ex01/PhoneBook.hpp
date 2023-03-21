
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "utils.hpp"


class PhoneBook
{
private:
	Contact	contacts[8];
public:

	PhoneBook(void);
	~PhoneBook(void);

	int		ChangeIndex(int i);
	void	AddContact(int i);
	int		PrintList(void);
	void	PrintContact(int i);
};

#endif