/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 18:46:47 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/03/17 18:49:04 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	stackZombie(name);
	stackZombie.announce();
}