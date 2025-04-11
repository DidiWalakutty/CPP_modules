/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 18:00:55 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/11 16:26:31 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

// Constructor: inits the name in one go
// It's an initilizer list, and assigns the value name to private 'name'
Zombie::Zombie(std::string name) : name(name) {}

// Destructor that outputs a message when zombie is destroyed.
Zombie::~Zombie()
{
	std::cout << name << " has been turned to dust forever!" << std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}