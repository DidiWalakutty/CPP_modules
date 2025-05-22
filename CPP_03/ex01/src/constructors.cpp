/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   constructors.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 14:16:45 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/22 15:13:38 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

/*
	ClapTrap Part
*/
ClapTrap::ClapTrap() : 
	_name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << BLUE << UNDERLINE << "ClapTrap default constructor called for " << _name << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : 
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << BLUE << "ClapTrap constructor called for " << _name << RESET << std::endl;
	printStatus();
}

ClapTrap::ClapTrap(const ClapTrap& copy) :
	_name(copy._name), _hitPoints(copy._hitPoints), 
	_energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage)
{
	std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
	printStatus();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& assign)
{
	std::cout << "ClapTrap copy assignment constructor called for " << _name << std::endl;
	if (this != &assign)	// safety check to avoid self-assignment
	{						// this = pointer to curr obj. &assign = address of the obj passed
		_name = assign._name;
		_hitPoints = assign._hitPoints;
		_energyPoints = assign._energyPoints;
		_attackDamage = assign._attackDamage;
	}
	printStatus();
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "Claptrap destructor called for " << _name << RESET << std::endl;
	printStatus();
}

/* 
	ScavTrap part 
*/
ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << CYAN << "ScavTrap default constructor called for " << _name << RESET << std::endl;
	printStatus();
}

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
	printStatus();
}

// We call ClapTrap's assignment operator to handle copying base attributes.
// This avoids duplicating code and ensures we copy the inherited data.
ScavTrap& ScavTrap::operator=(const ScavTrap& assign)
{
	std::cout << CYAN << "ScavTrap copy assignment constructor called for " << _name << RESET << std::endl;
	if (this != &assign)
		ClapTrap::operator=(assign);
	printStatus();
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap destructor called for " << _name << std::endl;
}