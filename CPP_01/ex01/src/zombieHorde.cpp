/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 19:45:48 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/11 16:54:02 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

// - Allocs memory for N zombies
// - Sets the name for each
// - Returns a pointer to the first zombie
Zombie*	zombieHorde(int N, std::string name)
{
	if (N < 1 || N > 500000)
	{
		std::cout << "Number of given zombies is invalid!" << std::endl;
		return (nullptr);
	}
	Zombie* horde = nullptr;
	try
	{
		// creates a block of n Zombies
		horde = new Zombie[N];
		// sets name for each zombie in the horde
		for (int i = 0; i < N; i++)
			horde[i].setName(name);
	}
	catch (const std::bad_alloc&)
	{
		std::cout << "Couldn't memory allocate your horde of zombies!" << std::endl;
		return (nullptr);
	}
	return (horde);
}