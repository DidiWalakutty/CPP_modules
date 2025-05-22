/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/21 19:15:24 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/22 14:44:50 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int	main()
{
	{
		std::cout << BG_WHITE << "Example 1" << RESET << std::endl;
		ClapTrap	bot("Grogu");
	
		bot.attack("Nazgul");
		bot.takeDamage(5);
		bot.beRepaired(10);
	}
	{
		std::cout << BG_WHITE << "Example 2" << RESET << std::endl;
		ClapTrap	bot("Sauron");

		bot.attack("Frodo");
		bot.takeDamage(20);
		bot.beRepaired(10);
		bot.attack("Sam");
		bot.takeDamage(1);
	}
	return (0);
}