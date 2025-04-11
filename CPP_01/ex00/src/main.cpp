/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 16:19:48 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/11 16:19:53 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

// Creates a zombie on either the heap or stack.
int	main()
{
	Zombie *heapZombie = newZombie("Heap the Undead");
	heapZombie->announce();
	delete heapZombie;	// delete the heap-allocated zombie to free memory
	
	// creats a zombie on the stack and announce immediately.
	randomChump("DeadStack");
	
	return (0);
}