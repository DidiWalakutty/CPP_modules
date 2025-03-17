/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 19:45:48 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/03/17 20:16:36 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

// alloc memory for 'n' zombies at once using new
// loop trough allocated zombies, init each one with the provided name
// return a pointer to the first zombie in the horde
// use delete to free the memory after testing

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* horde = nullptr;
	try
	{
		horde = new Zombie[N];
	}
	catch (const std::bad_alloc&)
	{
		std::cout << "Couldn't alloc your horde of zombies!" << std::endl;
		return nullptr;
	}
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return (horde);
}