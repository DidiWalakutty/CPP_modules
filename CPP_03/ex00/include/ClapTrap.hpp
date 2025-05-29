#pragma once

#include <iostream>
#include "color.hpp"
class ClapTrap
{
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
	
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& assign); // 1st &: returns ClapTrap& so we can a = b =c
		~ClapTrap();								 // 2nd &: copy safely by reference

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void printStatus() const;	// const: promises to not modify any member variables (private). Is read-only
};