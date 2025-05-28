/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/21 19:15:24 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/28 17:43:27 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int	main()
{
	// {
	// 	std::cout << BG_WHITE << "Example 1\n" << RESET << std::endl;
	// 	ClapTrap	bot("Grogu");
	
	// 	bot.attack("Nazgul");
	// 	bot.takeDamage(5);
	// 	bot.beRepaired(10);
	// }
	{
		std::cout << BG_WHITE << "Example 2\n" << RESET << std::endl;
		ClapTrap	bot("Sauron");

		bot.attack("Frodo");
		bot.takeDamage(5);
		bot.beRepaired(20);
		bot.attack("Sam");
		bot.takeDamage(1);
	}
	// {
	// 	std::cout << BG_WHITE << "Example 3\n" << RESET << std::endl;
	// 	ClapTrap	bot("Dr. Who");
	// 	ClapTrap	bot2;
	// 	ClapTrap	bot3("Care Bear");

	// 	bot3 = bot;
	// 	bot3.attack("Dalek");
	// 	bot3.beRepaired(1);
	// }
	return (0);
}