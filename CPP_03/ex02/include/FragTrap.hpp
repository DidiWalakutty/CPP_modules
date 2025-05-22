#pragma once

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& copy);
		FragTrap& operator=(const FragTrap& assign);
		~FragTrap();

		void highFivesGuys();
};