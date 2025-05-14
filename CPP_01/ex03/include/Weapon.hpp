#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

// 2nd const makes sure the function is read-only.
class Weapon
{
	private:
		std::string	type;
	
	public:
		Weapon(const std::string &type);
		const std::string& getType() const;
		void	setType(const std::string &newType);
};

#endif