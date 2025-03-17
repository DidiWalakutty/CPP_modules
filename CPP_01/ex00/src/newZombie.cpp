/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 18:22:09 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/03/17 20:31:09 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

// Directly creates a new Zombie on the heap and returns the pointer.
// if mem alloc fails, new catches it and a bad_alloc is thrown and caught.
// Nullptr has a dedicated type std::nullptr_t, NULL is an integer and 
// can cause assigning an int or can't determine which function/operation to use
// because both seem valid.
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