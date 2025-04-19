#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string	type;
	
	public:
		Weapon(const std::string &type); // constructor to init the weapon type
		// Returns a constant reference to the weapon's type.
		// The const at the end indicates this function
		// does not modify the Weapon object.
		const std::string& getType() const;
		// Sets the weapon's type to the new value provided by newType
		void	setType(const std::string &newType);
};

#endif