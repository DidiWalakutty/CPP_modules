/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/21 19:15:24 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/21 23:36:09 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int	main()
{
	// {
	// 	std::cout << MAGENTA << "\n--- ClapTrap Test ---\n" << RESET << std::endl;
	
	// 	ClapTrap grogu("Grogu");
		
	// 	grogu.attack("Darth Maul");
	// 	grogu.takeDamage(5);
	// 	grogu.beRepaired(10);
	// }
	{
		std::cout << MAGENTA << "\n---ScavTrap Test---\n" << RESET << std::endl;
	
		ScavTrap frodo("Frodo");
	
		frodo.attack("Boromir");
		frodo.takeDamage(150);
		frodo.beRepaired(15);
		frodo.guardGate();
	}
	// {
	// 	std::cout << MAGENTA << "\n--- Copy & Assignment Test ---\n" << RESET << std::endl;

	// 	ScavTrap drWho("Dr. Who");
	// 	ScavTrap copyDrWho(drWho);
	// 	ScavTrap assigned("Temp");

	// 	assigned = drWho;
	// }
	return (0);
}