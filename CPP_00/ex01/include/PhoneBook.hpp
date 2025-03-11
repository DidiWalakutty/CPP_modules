#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		num_contact;
	
	public:
		PhoneBook();
		void	addContact();
		void	searchContacts();
};

#endif