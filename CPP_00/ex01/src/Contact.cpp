/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 20:25:59 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/04 19:36:48 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

void Contact::setContact()
{
	first_name = checkName("First Name: ", "first");
	last_name = checkName("Last Name: ", "last");
	nick_name = checkName("Nickname: ", "nickname");
	phone_number = checkPhone();
	darkest_secret = checkSecret();
}

std::string Contact::checkName(const std::string &question, const std::string &type)
{
	std::string name;

	std::cout << question;
	if (!std::getline(std::cin, name))
	{
		std::cout << "\nEnd of input detected (Ctrl+D). Exiting program..." << std::endl;
		exit(1);
	}
	while (name.empty() || !spellingRules(name, type) || name.length() > 50)
	{
		std::cout << "\nInvalid input.\n";
		std::cout << "- Must be 1-50 characters long.\n";
		std::cout << "- No leading/trailing spaces.\n";
		if (type == "first" || type == "last")
			std::cout << "- Letters, spaces, and hyphens only.\n";
		else if (type == "nickname")
			std::cout << "- Can include letters, numbers, symbols, spaces, and hyphens.\n";
		std::cout << "\nPlease re-enter - " << question;
		if (!std::getline(std::cin, name))
		{
			std::cout << "\nEnd of input detected (Ctrl+D). Exiting program..." << std::endl;
			exit(1);	
		}
	}
	return (name);
}

std::string Contact::checkPhone()
{
	std::string phone;

	std::cout << "Phone Number: ";
	if (!std::getline(std::cin, phone))
	{
		std::cout << "End of input detected (Ctrl+D). Exiting program..." << std::endl;
		exit(1);
	}
	while (phone.empty() || !phoneRules(phone) || phone.length() > 15)
	{
		std::cout << "\nInvalid phone number.\n\n";
		std::cout << "- 7+ digits, may start with '+'\n.";
		std::cout << "- Max 15 characters, up to 3 dashes.\n";
		std::cout << "- Must end in a digit.\n\n";
		std::cout << "Please re-enter the phonenumber: ";
		if (!std::getline(std::cin, phone))
		{
			std::cout << "\nEnd of input detected (Ctrl+D). Exiting program..." << std::endl;
			exit(1);
		}
	}
	return (phone);
}

std::string Contact::checkSecret()
{
	std::string secret;

	std::cout << "Darkest Secret: ";
	if (!std::getline(std::cin, secret))
	{
		std::cout << "\nEnd of input detected (Ctrl+D). Exiting program..." << std::endl;
		exit(1);
	}
	while (secret.empty() || !secretRules(secret) || secret.length() > 50)
	{
		std::cout << "\nInvalid input.\n";
		std::cout << "- 1-50 characters.\n";
		std::cout << "- No newlines, tabs, or outer spaces.\n";
		std::cout << "Please re-enter the darkest secret: ";
		if (!std::getline(std::cin, secret))
		{
			std::cout << "\nEnd of input detected (Ctrl+D). Exiting program...\n" << std::endl;
			exit(1);
		}
	}
	return (secret);
}

void	Contact::printContacts(int i)
{
	std::cout << std::setw(10) << i << "|"
			  << std::setw(10) << truncate(first_name) << "|"
			  << std::setw(10) << truncate(last_name) << "|"
			  << std::setw(10) << truncate(nick_name) << std::endl;
}

void	Contact::printFullContact()
{
	std::cout << "First Name: " << first_name << "\n";
	std::cout << "Last Name: " << last_name << "\n";
	std::cout << "Nickname: " << nick_name << "\n";
	std::cout << "Phone Number: " << phone_number << "\n";
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}