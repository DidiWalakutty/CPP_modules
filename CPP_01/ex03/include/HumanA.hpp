#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"

// Human A will always be armed.
// Uses a reference, because HumanA must always have a weapon.
// A reference requires that a weapon is passed in construction.
// It can't be NULL.
class HumanA
{
	private:
		std::string	name;
		Weapon &currentWeapon;
	
	public:
		HumanA(const std::string& name, Weapon& currentWeapon);
		void	attack() const;
};

#endif