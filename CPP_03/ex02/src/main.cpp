/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 21:24:54 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/22 21:54:00 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

int	main()
{
	// {
	// 	std::cout << BG_MAGENTA << "\n--- ClapTrap Basic Test ---\n" << RESET << std::endl;
	// 	ClapTrap basic("Ratatouille");

	// 	basic.attack("Lumiere");
	// 	basic.takeDamage(5);
	// 	basic.beRepaired(3);
	// }
	// {
	// 	std::cout << BG_MAGENTA << "\n--- ScavTrap Gate Keeper Test ---\n" << RESET << std::endl;
	// 	ScavTrap guard("Wall-E");

	// 	guard.attack("a Stormtrooper");
	// 	guard.takeDamage(30);
	// 	guard.beRepaired(10);
	// 	guard.guardGate();
	// }
	{
		std::cout << MAGENTA << "\n--- FragTrap Test---\n" << RESET << std::endl;
		FragTrap frag("Darth Vader");

		frag.attack("a jedi kid");
		frag.takeDamage(10);
		frag.beRepaired(25);
		frag.highFivesGuys();
	}
	// {
	// 	std::cout << BG_MAGENTA << "\n--- Copy & Assign Test---\n" << RESET << std::endl;
	// 	FragTrap original("OG_Fraggie");
	// 	FragTrap copy(original);
	// 	FragTrap assigned("Temp");

	// 	assigned = original;
	// 	assigned.highFivesGuys();
	// }
	return (0);
}