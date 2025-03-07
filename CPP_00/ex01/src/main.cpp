/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 17:31:45 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/03/06 21:19:56 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"
#include <iostream>

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
			std::cout << "\nDetected ctrl+d. Exiting..." << std::endl;
			break ;
		}
		if (command == "ADD")
			myContacts.addContact();
		else if (command == "SEARCH")
			myContacts.searchContacts();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command." << std::endl;
	}
}