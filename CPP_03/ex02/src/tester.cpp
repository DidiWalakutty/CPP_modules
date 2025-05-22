/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 21:58:23 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/22 21:59:09 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

// c++ -Wall -Wextra -Werror -std=c++98 tester.cpp ClapTrap.cpp ScavTrap.cpp constructors.cpp FragTrap.cpp -o tester
// ./tester
int	main()
{
	{
		std::cout << BG_MAGENTA << "\n--- ClapTrap Basic Test ---\n" << RESET << std::endl;
		ClapTrap basic("Ratatouille");

		basic.attack("Lumiere");
		basic.takeDamage(5);
		basic.beRepaired(3);
	}
	{
		std::cout << BG_MAGENTA << "\n--- ScavTrap Gate Keeper Test ---\n" << RESET << std::endl;
		ScavTrap guard("Wall-E");

		guard.attack("a Stormtrooper");
		guard.takeDamage(30);
		guard.beRepaired(10);
		guard.guardGate();
	}
	{
		std::cout << BG_MAGENTA << "\n--- Copy & Assign Test---\n" << RESET << std::endl;
		FragTrap original("OG_Fraggie");
		FragTrap copy(original);
		FragTrap assigned("Temp");

		assigned = original;
		assigned.highFivesGuys();
	}
	return (0);
}