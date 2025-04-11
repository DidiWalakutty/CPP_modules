/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 19:40:27 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/11 16:55:14 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"


// Function where a zombie announces itself.
// Need to determine in which case we allocate on stack or heap.
// 
int	main()
{
	int	N = 15;
	std::string name = "The Walking Dead";
	//Creates a horde of N zombies with the given name
	Zombie* horde = zombieHorde(N, name);

	// Each zombie announces itself
	if (horde)
	{
		for (int i = 0; i < N; i++)
			horde[i].announce();
		delete[] horde;
	}
	return (0);
}