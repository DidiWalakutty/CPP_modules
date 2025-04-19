/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/11 18:04:56 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/19 22:00:26 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), currentWeapon(nullptr) {}

void HumanB::setWeapon(Weapon& weapon)
{
	this->currentWeapon = &weapon;
}

void HumanB::attack()
{
	if (currentWeapon)
		std::cout << name << " attacks with their " << currentWeapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon to defend themselves with!" << std::endl;
}
