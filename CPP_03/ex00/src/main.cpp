/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/21 19:15:24 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/21 20:37:10 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int	main()
{
	{
		ClapTrap	bot("Grogu");
	
		bot.printStatus();
		bot.attack("Nazgul");
		bot.takeDamage(5);
		bot.beRepaired(10);
	}
	{
		ClapTrap	bot("Sauron");

		bot.printStatus();
		bot.attack("Frodo");
		bot.takeDamage(20);
		bot.beRepaired(10);
		bot.attack("Sam");
		bot.takeDamage(1);
	}
}