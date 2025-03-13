/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 20:25:59 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/03/13 17:44:25 by diwalaku      ########   odam.nl         */
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
		std::cout << "\nDetected ctrl+d. Exiting..." << std::endl;
		exit(1);
	}
	while (name.empty() || !spellingRules(name, type) || name.length() > 50)
	{
		std::cout << "\nYour input is invalid.\n\n";
		std::cout << "Please note: your input can't be empty, over 50 characters or start/end with spaces.\n";
		if (type == "first")
			std::cout << "First names can only contain letters and spaces. No special characters or numbers.\n";
		if (type == "last")
			std::cout << "Last names can only contain letters, spaces and hyphens. No other special characters or numbers.\n";
		if (type == "nickname")
			std::cout << "Nicknames can contain letters, spaces, hyphens, numbers and special characters.\n";
		std::cout << "\nPlease re-enter - " << question;
		if (!std::getline(std::cin, name))
		{
			std::cout << "\nDetected ctrl+d. Exiting..." << std::endl;
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
		std::cout << "Detected ctrl+d. Exiting..." << std::endl;
		exit(1);
	}
	while (phone.empty() || !phoneRules(phone) || phone.length() > 15)
	{
		std::cout << "\nYour phone input is invalid.\n\n";
		std::cout << "- The phonenumber may start with a '+'.\n- It may contain up to 3 dashes.\n";
		std::cout << "- It must have a minimum of 7 digits and must end with a digit.\n";
		std::cout << "- The phonenumber can't contain more than 15 characters\n\n";
		std::cout << "Please re-enter the phonenumber: ";
		if (!std::getline(std::cin, phone))
		{
			std::cout << "\nDetected ctrl+d. Exiting..." << std::endl;
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
		std::cout << "\nDetected ctrl+d. Exiting..." << std::endl;
		exit(1);
	}
	while (secret.empty() || !secretRules(secret) || secret.length() > 50)
	{
		std::cout << "\nThe input for darkest secret is invalid.\n\n";
		std::cout << "- It can't be empty or contain newlines or tabs.\n";
		std::cout << "- It can't start or end with whitespace.\n";
		std::cout << "- It can't contain more than 50 characters.\n";
		std::cout << "Please re-enter the darkest secret: ";
		if (!std::getline(std::cin, secret))
		{
			std::cout << "\nDetected ctrl+d. Exiting...\n" << std::endl;
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