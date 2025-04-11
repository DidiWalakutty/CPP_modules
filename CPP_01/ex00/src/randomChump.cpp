/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 18:46:47 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/11 16:20:54 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

// Creates a stack-allocated zombie that goes
// out of scope after this function.
// Immediately announces itself.
void	randomChump(std::string name)
{
	Zombie	stackZombie(name);
	stackZombie.announce();
}