/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 16:30:35 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/30 17:10:09 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl is here. The complaints are strong with this one...\n" << std::endl;
}

void Harl::debug()
{
	std::cout << "I find your lack of documentation... disturbing\n" << std::endl;
}

void Harl::info()
{
	std::cout << "This is the way! Or at least, mostly... Let's get more data!\n" << std::endl;
}

void Harl::warning()
{
	std::cout << "I've got a bad feeling about this function...\n" << std::endl;
}

void Harl::error()
{
	std::cout << "The system has turned to the Dark Side! Execute Order 67!\n" << std::endl;
}

// Define an array of function pointers (whiningLevel). 
// Each element in it a pointer to a member function of the Harl class. 
// Harl::* defines pointers to member of Harl.
// () indicates that the functions take no parameters.
// Each element of the array now points to one of the four complaint functions.
void Harl::complain(std::string level)
{
	void (Harl::*whiningLevel[4])() =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string stringLevel[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
	{
		if (stringLevel[i] == level)
		{
			(this->*whiningLevel[i])();
			return ;
		}
	}
	std::cout << "* This isn't the Level you're looking for... *" << std::endl;
}