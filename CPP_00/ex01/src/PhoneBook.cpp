/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 20:24:17 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/03/12 16:16:32 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>

PhoneBook::PhoneBook() : num_contact(0) {}

void	PhoneBook::addContact()
{
	contacts[num_contact % 8].setContact();
	num_contact++;
}

void	PhoneBook::searchContacts()
{
	if (num_contact == 0)
	{
		std::cout << "Your phonebook is currently empty." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << std::right << "index" << "|"
			  << std::setw(10) << std::right << "first name" << "|"
			  << std::setw(10) << std::right << "last name" << "|"
			  << std::setw(10) << std::right << "nickname" << "|" << std::endl;
	std::cout << std::setw(40) << std::setfill('_') << std::endl;
	for (int i = 0; i < std::min(num_contact, 8); i++)
		contacts[i].printContacts(i);
	std::string input_i;
	int	index;
	std::cout << "Please enter index: \n";
	if (!std::getline(std::cin, input_i))
	{
		std::cout << "Detected ctrl+d. Exiting...\n" << std::endl;
		exit(1);
	}
	if (!input_i.empty() && std::isdigit(input_i[0]) && input_i.length() == 1)
	{
		index = std::stoi(input_i);
		if (index >= 0 && index < std::min(num_contact, 8))
			contacts[index].printFullContact();
		else
			std::cout << "Given index is invalid" << std::endl;
	}
	else
		std::cout << "Given index is invalid" << std::endl;		
}
