
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iomanip>
# include <iostream>
# define LOG(x) std::cout << x << std::endl

class Contact
{
private:
	int	_index;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone;
	std::string	_secret;
public:
	Contact(void);
	~Contact(void);

	void	addContact(int i, std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret);
	void	PrintPrivateInfo(void);
	void	PrintPublicInfo(void);
	int		CheckIfEmpty(void);
};




#endif