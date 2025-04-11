/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 18:22:09 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/11 16:22:50 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

// Tries to alloc a new zombie on the heap.
// If alloc fails, new thros a bad_alloc.
Zombie*	newZombie(std::string name)
{
	try
	{
		return new Zombie(name);
	}
	catch (const std::bad_alloc&)
	{
		std::cout << "Memory allocation failed\n";
		return (nullptr);
	}
}