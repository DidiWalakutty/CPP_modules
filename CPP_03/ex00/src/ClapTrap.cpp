/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/21 19:55:27 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/22 12:04:53 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

void ClapTrap::printStatus() const
{
	std::cout << "\n[" << _name << "'s Status]" << std::endl;
	std::cout << "| HP: " << _hitPoints
			  << " | EP: " << _energyPoints
			  << " | AP: " << _attackDamage << " |\n"
			  << "_________________________\n" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << YELLOW << _name << " attacks " << target << "! It caused " << _attackDamage << " points of damage!" << RESET << std::endl;
		_energyPoints--;
		printStatus();
	}
	else
	{
		std::cout << _name << " can't attack. " << _name << " doesn't have any Energy or Hit Points available." << std::endl;
		printStatus();
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << RED << _name << " has taken " << amount << " of damage!" << RESET << std::endl;
		_hitPoints -= amount;
		if (_hitPoints < 0) 
			_hitPoints = 0;
		printStatus();
	}
	else
	{
		std::cout << RED << _name << "has died... It has no HP left." << RESET << std::endl;
		printStatus();
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << GREEN << _name << " has repaired itself with " << amount << " Hit Points!" << RESET << std::endl;
		_hitPoints += amount;
		_energyPoints--;
		printStatus();
	}
	else
	{
		std::cout << _name << " couldn't repair itself, it has no EP or HP!";
		printStatus();
	}
}