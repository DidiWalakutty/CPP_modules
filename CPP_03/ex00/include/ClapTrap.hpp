#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

constexpr char RED[]    = "\033[31m";
constexpr char GREEN[]  = "\033[32m";
constexpr char YELLOW[] = "\033[33m";
constexpr char BLUE[]   = "\033[34m";
constexpr char MAGENTA[]= "\033[35m";
constexpr char CYAN[]   = "\033[36m";
constexpr char RESET[]  = "\033[0m";

class ClapTrap
{
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int	_attackDamage;
	
	public:
		ClapTrap(const std::string& name);	// & = reference
		ClapTrap(const ClapTrap& copy);		// Claptrap& = passing existing obj by reference
		ClapTrap& operator=(const ClapTrap& assign); // 1st &: returns ClapTrap& so we can a = b =c
		~ClapTrap();								 // 2nd &: copy safely by reference

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void printStatus() const;	// const: promises to not modify any member variables (private). Is read-only
};


#endif