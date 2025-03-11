#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string	first_name, last_name, nick_name, phone_number, darkest_secret;
		std::string	checkName(const std::string &question, const std::string &type);
		bool		spellingRules(const std::string &name, const std::string &type);
		std::string	checkPhone();
		bool		phoneRules(const std::string &phone);
		std::string checkSecret();
		bool		secretRules(const std::string &secret);
		std::string	truncate(const std::string &name);

	public:
		void		setContact();
		void		printContacts(int i);
		void		printFullContact();	
};

#endif