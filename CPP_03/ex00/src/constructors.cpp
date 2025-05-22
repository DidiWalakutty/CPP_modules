/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   constructors.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/21 19:18:34 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/22 21:10:06 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : 
	_name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << BLUE << UNDERLINE << "ClapTrap default constructor called for " << _name << RESET << std::endl;
	printStatus();
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
	std::cout << RED << "Claptrap's new name is: " << _name << RESET << std::endl;
	printStatus();
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << BG_RED << "ClapTrap destructor called for " << _name << RESET << std::endl;
}