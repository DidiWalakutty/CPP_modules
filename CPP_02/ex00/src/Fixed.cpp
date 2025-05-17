/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 18:56:51 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/17 12:30:47 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedValue = copy._fixedValue;
	this->getRawBits();
}

// Fixed& allows chaining assignments (a = b = c)
Fixed& Fixed::operator=(const Fixed& copyAssign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copyAssign)
		this->_fixedValue = copyAssign._fixedValue;
	this->getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedValue = raw;
}