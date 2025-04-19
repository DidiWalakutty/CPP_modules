#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"

// Weapon is a *, so we don't have a weapon initially.
// A * can start as a nullptr and assign a weapon later.
class HumanB
{
	private:
		std::string name;
		Weapon *currentWeapon;
	public:
		HumanB(const std::string& name);
		void setWeapon(Weapon& currentWeapon);
		void attack();
};

#endif