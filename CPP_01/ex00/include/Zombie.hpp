#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie(std::string name);	// Constructor: sets up the object when created and inits the zombies name
		~Zombie();					// Destructor: cleans up (frees memory) when the zombie is destroyed
		void	announce();			// Outputs a message from the zombie
};

// Function to create a zombie on the heap (dynamic alloc)
Zombie* newZombie(std::string name);
// Function to create and announce a zombie on the stack (temporary)
void	randomChump(std::string name);

#endif