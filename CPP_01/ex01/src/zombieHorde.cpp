/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 19:45:48 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/03/17 20:32:20 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* horde = nullptr;
	try
	{
		horde = new Zombie[N];
	}
	catch (const std::bad_alloc&)
	{
		std::cout << "Couldn't memory allocate your horde of zombies!" << std::endl;
		return nullptr;
	}
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return (horde);
}