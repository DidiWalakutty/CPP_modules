/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 16:30:35 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/01 18:19:22 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl()
{
	std::cout << "[INITIALIZED]\n";
	std::cout << "Harl is here. The complaints are strong with this one...\n" << std::endl;
}

Harl::~Harl()
{
	std::cout << "[LEFT]\n";
	std::cout << "Harl out! May your code be bug-free!" << std::endl;
}

void Harl::debug()
{
	std::cout << "[DEBUG]\n";
	std::cout << "I find your lack of documentation... disturbing\n" << std::endl;
}

void Harl::info()
{
	std::cout << "[INFO]\n";
	std::cout << "This is the way! Or at least, mostly... Let's get more data!\n" << std::endl;
}

void Harl::warning()
{
	std::cout << "[WARNING]\n";
	std::cout << "I've got a bad feeling about this function...\n" << std::endl;
}

void Harl::error()
{
	std::cout << "[ERROR]\n";
	std::cout << "The system has turned to the Dark Side! Execute Order 67!\n" << std::endl;
}

// Define an array of function pointers (whiningLevel), each element points to a function.
// Harl::* defines pointers to member of Harl, (): functions takes no parameters.
// The array stores the functions' addresses and points to one of the functions.
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
	std::cout << "[UNKNOWN]\n";
	std::cout << "* This isn't the Level you're looking for... *\n" << std::endl;
}