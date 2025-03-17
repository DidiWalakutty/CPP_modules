/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 18:22:09 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/03/17 19:13:18 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

// Directly creates a new Zombie on the heap and returns the pointer.
// if mem alloc fails, new catches it and a bad_alloc is thrown and caught.
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