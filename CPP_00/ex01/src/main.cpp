/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 17:31:45 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/03/17 18:40:39 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"
#include <iostream>

// Constructor is automatically called, because myContacts
// is being created directly on the stack

int	main(void)
{
	PhoneBook	myContacts;
	std::string	command;

	std::cout << "Welcome to your PhoneBook!" << std::endl;
	while (1)
	{
		std::cout << "Please enter ADD, SEARCH or EXIT: ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nEnd of input detected (Ctrl+D). Exiting program..." << std::endl;
			break ;
		}
		if (command == "ADD")
			myContacts.addContact();
		else if (command == "SEARCH")
			myContacts.searchContacts();
		else if (command == "EXIT")
			break ; // or exit(1)?
		else
			std::cout << "Invalid command." << std::endl;
	}
}