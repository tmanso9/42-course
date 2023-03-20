
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# define LOG(x) std::cout << x << std::endl

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone;
	std::string	secret;
public:
	Contact(void);
	~Contact(void);

	void	addContact(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret);
	void	printInfo(void);
};




#endif