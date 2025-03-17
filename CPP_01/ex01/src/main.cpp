/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 19:40:27 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/03/17 20:22:15 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

// call the zombieHorde function with a test value
// use announce function for each zombie
// deallocate the horde memory
int	main()
{
	int	N = 10;
	if (N <= 2)
	{
		std::cout << "Number of zombies is too small for a horde." << std::endl;
		return 1;
	}

	std::string name = "The Walking Dead";
	Zombie* horde = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}