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


// Changed private to public: Now the derived class ScavTrap can access and init this Base class directly. 
//		This keeps the inheritance clean and avoids unnecessary setters or duplicate variables.
class ClapTrap
{
	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int	_attackDamage;
	
	public:
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& assign);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void printStatus() const;
};


#endif