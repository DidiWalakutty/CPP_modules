/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 21:54:52 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/22 21:57:51 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

// c++ -Wall -Wextra -Werror -std=c++98 tester.cpp ClapTrap.cpp ScavTrap.cpp constructors.cpp -o tester
// ./tester
int	main()
{
	{
		std::cout << BG_MAGENTA << "\n--- ClapTrap Test ---\n" << RESET << std::endl;
	
		ClapTrap grogu("Grogu");
		
		grogu.attack("Darth Maul");
		grogu.takeDamage(5);
		grogu.beRepaired(10);
	}
	{
		std::cout << BG_MAGENTA << "\n--- Copy & Assignment Test ---\n" << RESET << std::endl;

		ScavTrap drWho("Dr. Who");
		ScavTrap copyDrWho(drWho);
		ScavTrap assigned("Temp");

		assigned = drWho;
		assigned.attack("a Dalek");
		assigned.takeDamage(95);
		assigned.beRepaired(200);
		assigned.guardGate();
	}
}