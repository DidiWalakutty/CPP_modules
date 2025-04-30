/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 17:44:47 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/30 18:03:22 by diwalaku      ########   odam.nl         */
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

int	determine_level(std::string level)
{
	if (level == "DEBUG")
		return (0);
	if (level == "INFO")
		return (1);
	if (level == "WARNING")
		return (2);
	if (level == "ERROR")
		return (3);
	else
		return (-1);
}

// We store the four Harl functions in an array of function pointers.
// The level-string is turned into a number using determine_level(), because switch only works with ints.
// The switch starts at that case-number and runs all matching messages after it.
// If the level isn't valid, we show a default message instead.
// This avoids using lots of if/else statements.
void Harl::complain(std::string level)
{
	void (Harl::*whiningLevel[4])() =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	int index = determine_level(level);
	
	switch (index)
	{
		case 0:
			(this->*whiningLevel[0])();
		case 1:
			(this->*whiningLevel[1])();
		case 2:
			(this->*whiningLevel[2])();
		case 3:
			(this->*whiningLevel[3])();
			break ;
		default:
			std::cout << "[UNKNOWN]\n";
			std::cout << "* This isn't the Level you're looking for... *\n" << std::endl;
			break ;
	}
}