#include <string>

class Contact
{
	private:
		std::string	first_name, last_name, nick_name, phone_number, darkest_secret;
		std::string	check_name(const std::string &question, const std::string &type);
		bool		spellingrules(const std::string &name, const std::string &type);
		std::string	check_phone();
		bool		phonerules(const std::string &phone);
		std::string check_secret();
		// truncate?
	public:
		void		setContact();
		void		printContacts();
		void		printFullContact();	
};