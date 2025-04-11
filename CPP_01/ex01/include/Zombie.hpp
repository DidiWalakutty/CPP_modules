#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		~Zombie();
		void	setName(std::string name);	// Sets the zombie's name
		void 	announce() const;
};

// Creates a horde of N zombies with the same name
Zombie* zombieHorde(int N, std::string name);

#endif