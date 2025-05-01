/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/11 18:05:01 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/01 16:33:22 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(const std::string &type): type(type) {}

const std::string& Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType(const std::string &newType)
{
	this->type = newType;
}