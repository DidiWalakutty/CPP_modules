#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "color.hpp"
#include <iostream>
#include <string>

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