/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 19:35:14 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/15 15:13:08 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _fixedValue(0)
{	
	std::cout << "Default constructor called" << std::endl;
}

// Shift the int left by 8 bits to move it into fixed-point format.
// This stores the int correctly by reserving the lower 8 bits for the fractional part.
Fixed::Fixed(const int fixedInt)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = fixedInt << _fractBits;
}

// Multiply the float by 256 (1 << 8) to scale it up to fixed-point format
// and use roundf to choose the closest int value that represents the fixed-point num accurately.
Fixed::Fixed(const float fixedFloat)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedValue = roundf(fixedFloat * (1 << _fractBits));
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedValue = copy._fixedValue;
}

Fixed& Fixed::operator=(const Fixed& copyAssign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copyAssign)
		this->_fixedValue = copyAssign._fixedValue;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// toFloat(): converts fixed-point back to float by dividing by 256 (1 << _fractBits).
float	Fixed::toFloat() const
{
	return (float)_fixedValue / (1 << _fractBits);
}

// toInt(): drops the fractional bits by shifting right, returning only the int part.
int		Fixed::toInt() const
{
	return _fixedValue >> _fractBits;
}

// Tells the compiler how to print a Fixed object with << class Object.
// Overloads << to print Fixed objects as floats.
// 'os' holds the current stream (e.g. "a is ") and adds toFloat().
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}