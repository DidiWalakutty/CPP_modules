/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 16:19:48 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/03/17 18:54:04 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

// We're working with dynamic memory and creating a Zombie on the heap.
// The constructor is called inside newZombie when calling new Zombie(...).
// 'new' automatically calls the constructor during memory allocation.

// randomChump should be on the stack: it's just to announce
// newZombie should be on the heap: we need to use it outside the function scope
int	main()
{
	Zombie *heapZombie = newZombie("UndeadHeap");
	heapZombie->announce();
	delete heapZombie;
	
	randomChump("UndeadStack");
	
	return (0);
}