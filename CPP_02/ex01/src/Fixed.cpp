/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 19:35:14 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/17 12:30:08 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _fixedValue(0)
{	
	std::cout << "Default constructor called" << std::endl;
}

// Shift int left by 8 bits to store it as fixed-point.
// This moves int into higher bits, reserving lower 8 for decimals.
Fixed::Fixed(const int fixedInt)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = fixedInt << _fractBits;
}

// Multiply float by 256 (1 << 8) and round to convert to fixed-point.
// This way we can store both int and fractional parts in one int value.
// Uses roundf to choose the closest int value that represents the fixed-point num accurately.
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
// When creating the float constructor, we multiplied it by 256 to fit in an int.
float	Fixed::toFloat() const
{
	return (float)_fixedValue / (1 << _fractBits);
}

// toInt(): drops the fractional bits by shifting right, returning only the int part.
int		Fixed::toInt() const
{
	return _fixedValue >> _fractBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}