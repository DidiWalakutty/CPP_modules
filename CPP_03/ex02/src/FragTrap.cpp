/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 21:26:44 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/22 21:51:25 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

void FragTrap::highFivesGuys()
{
	if (this->_energyPoints > 0)
		std::cout << BG_GREEN << _name << " enthusiastically throws both hands up for a high five!" << RESET << std::endl;
	else
		std::cout << BG_GREEN << _name << " didn't have enough EP to ask for a high five..." << RESET << std::endl;
}