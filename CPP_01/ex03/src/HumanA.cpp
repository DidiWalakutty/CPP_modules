/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/11 18:04:58 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/19 21:13:50 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), currentWeapon(weapon) {}

void HumanA::attack() const
{
	std::cout  << name << " attacks with their " << currentWeapon.getType() << std::endl;
}