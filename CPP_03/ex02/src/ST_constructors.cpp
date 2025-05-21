/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ST_constructors.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/21 22:58:12 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/21 23:16:11 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << CYAN << "ScavTrap constructor called for " << name << RESET << std::endl;
	printStatus();
}

// Copy constructor calls the ClapTrap copy constructor
// to copy the base class part of the ScavTrap.
ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	std::cout << CYAN << "ScavTrap copy constructor called for " << _name << RESET << std::endl;
}

// We call ClapTrap's assignment operator to handle copying base attributes.
// This avoids duplicating code and ensures we copy the inherited data.
ScavTrap& ScavTrap::operator=(const ScavTrap& assign)
{
	std::cout << CYAN << "ScavTrap copy assignment constructor called for " << _name << RESET << std::endl;
	if (this != &assign)
		ClapTrap::operator=(assign);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap destructor called for " << _name << std::endl;
}