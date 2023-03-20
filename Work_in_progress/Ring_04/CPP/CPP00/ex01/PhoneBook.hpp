
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define LOG(x) std::cout << x << std::endl

class PhoneBook
{
private:
	Contact	contacts[8];
public:

	PhoneBook(void);
	~PhoneBook(void);

	void	AddContact(void);
	void	PrintContact(int i);

	static int	index;
};

#endif