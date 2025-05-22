/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/21 22:32:30 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/22 14:49:10 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << YELLOW << "ScavTrap - " << _name << " attacks " << target << "! It caused " << _attackDamage << " points of damage!" << RESET << std::endl;
		_energyPoints--;
		printStatus();
	}
	else
	{
		std::cout << YELLOW << ITALIC << "ScavTrap - " << _name << " can't attack. " << _name << " doesn't have enough Energy or Hit Points available." << RESET << std::endl;
		printStatus();
	}
}

void ScavTrap::guardGate()
{
	if (_hitPoints > 0)
		std::cout << BG_YELLOW << "ScavTrap " << _name << " is now in Gate Keeper mode!" << RESET << std::endl;
	else
		std::cout << BG_YELLOW << "ScavTrap " << _name << " is out of HP and can't go into Gate Keeper mode!" << RESET << std::endl;
}