#pragma once

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

// Derived class from Base class ClapTrap
class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& copy);
		ScavTrap& operator=(const ScavTrap& assign);
		~ScavTrap();

		void attack(const std::string& target);	// Overwrites OG attack
		void guardGate();
};