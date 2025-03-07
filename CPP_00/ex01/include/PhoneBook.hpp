#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		pos;
	
	public:
		PhoneBook();	// 
		void	addContact();
		void	searchContacts();
};