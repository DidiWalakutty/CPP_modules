#pragma once

#include <iostream>
#include "color.hpp"
class ClapTrap
{
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int	_attackDamage;
	
	public:
		ClapTrap();
		ClapTrap(const std::string& name);	// & = reference
		ClapTrap(const ClapTrap& copy);		// Claptrap& = passing existing obj by reference
		ClapTrap& operator=(const ClapTrap& assign); // 1st &: returns ClapTrap& so we can a = b =c
		~ClapTrap();								 // 2nd &: copy safely by reference

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void printStatus() const;	// const: promises to not modify any member variables (private). Is read-only
};