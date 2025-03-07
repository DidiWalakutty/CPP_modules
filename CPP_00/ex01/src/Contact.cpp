/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 20:25:59 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/03/06 23:00:48 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include <iostream>
#include <cctype>

void Contact::setContact()
{
	first_name = check_name("First Name: ", "first");
	last_name = check_name("Last Name: ", "last");
	nick_name = check_name("Nickname: ", "nickname");
	phone_number = check_phone();
	darkest_secret = check_secret();
}

std::string Contact::check_name(const std::string &question, const std::string &type)
{
	std::string name;

	std::cout << question;
	if (!std::getline(std::cin, name))
	{
		std::cout << "\nDetected ctrl+d. Exiting..." << std::endl;
		exit(1);
	}
	while (name.empty() || !spellingrules(name, type))
	{
		std::cout << "Your input is invalid.\n";
		std::cout << "Please note: there can't be spaces at the start or end of your input.\n\n";
		if (type == "first")
			std::cout << "First names can only contain letters and spaces. No special characters or numbers.\n";
		if (type == "last")
			std::cout << "Last names can only contain letters, spaces and hyphens. No other special characters or numbers.\n";
		if (type == "nickname")
			std::cout << "Nicknames can contain letters, spaces, hyphens, numbers and special characters.\n";
		std::cout << "\nPlease re-enter - " << question << "\n";
		if (!std::getline(std::cin, name))
		{
			std::cout << "\nDetected ctrl+d. Exiting..." << std::endl;
			exit(1);	
		}
	}
	return (name);
}

std::string Contact::check_phone()
{
	std::string phone;

	std::cout << "Phone Number: ";
	if (!std::getline(std::cin, phone))
	{
		std::cout << "Detected ctrl+d. Exeting..." << std::endl;
		exit(1);
	}
	while (phone.empty() || !phonerules(phone))
	{
		std::cout << "Your phone input is invalid.\n";
		std::cout << "- Your phonenumber may start with a '+'.\n- It may contain up to 3 dashes.\n- It must have a minimum of 7 digits and end with a digit.\n";
		std::cout << "Please re-enter the phonenumber: \n";
		if (!std::getline(std::cin, phone))
		{
			std::cout << "\nDetected ctrl+d. Exiting..." << std::endl;
			exit(1);
		}
	}
	return (phone);
}