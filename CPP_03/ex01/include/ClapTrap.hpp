#pragma once

#include <iostream>
#include <string>
#include "color.hpp"

// Changed private to protected: Now the derived class ScavTrap can access and init this Base class directly. 
//		This keeps the inheritance clean and avoids unnecessary setters or duplicate variables.
class ClapTrap
{
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
	
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& assign);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void printStatus() const;
};
