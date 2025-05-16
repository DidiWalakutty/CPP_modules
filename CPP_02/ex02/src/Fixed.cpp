/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/15 15:24:29 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/16 16:40:15 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _fixedValue(0) {}

// Shift the int left by 8 bits for fixed-point format.
// This stores the int correctly by reserving the lower 8 bits for the fractional part.
Fixed::Fixed(const int fixedInt)
{
	this->_fixedValue = fixedInt << _fractBits;
}

// Multiply the float by 256 (1 << 8) to scale it up to fixed-point format
// and use roundf to choose the closest int value that represents the fixed-point num accurately.
Fixed::Fixed(const float fixedFloat)
{
	this->_fixedValue = roundf(fixedFloat * (1 << _fractBits));
}

Fixed::Fixed(const Fixed& copy)
{
	this->_fixedValue = copy._fixedValue;
}

Fixed& Fixed::operator=(const Fixed& copyAssign)
{
	if (this != &copyAssign)
		this->_fixedValue = copyAssign._fixedValue;
	return *this;
}

Fixed::~Fixed() {}

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

// Tells the compiler how to print a Fixed object with << 'class Object'
// Overloads << to print Fixed objects as floats.
// 'os' holds the current stream (e.g. "a is ") and adds toFloat().
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

/* Comparison Operators */ 
bool Fixed::operator>(const Fixed& other) const
{
	return this->_fixedValue > other._fixedValue;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->_fixedValue < other._fixedValue;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->_fixedValue >= other._fixedValue;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->_fixedValue <= other._fixedValue;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->_fixedValue == other._fixedValue;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_fixedValue != other._fixedValue;
}

/* Arithmetic Operators */
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result._fixedValue = this->_fixedValue + other._fixedValue;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result._fixedValue = this->_fixedValue - other._fixedValue;
	return (result);
}

/*  Multiply the two integer values.
    Each is scaled by 256, so the product is scaled by 256 twice (64 bit, too big).
	We shift right by 8 bits to fix the scale back to normal.
	Use long long to avoid overflow during multiplication.
*/
Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;

	long long temp = static_cast<long long>(this->_fixedValue) * other._fixedValue;
	result._fixedValue = static_cast<int>(temp >> _fractBits);
	return result;
}

/* We first multiply by 256 (left shift) so we don't lose precision.
   We then divide by the denominator's (other._fixedValue) value.
   Long long to avoid overflow and store result in an int again.*/
Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;

	long long temp = (static_cast<long long>(this->_fixedValue) << _fractBits) / other._fixedValue;
	result._fixedValue = static_cast<int>(temp);
	return result;
}

/* Increment and Decrement Operators 
	Pre = increment and use new value
	Post = Use the value, then increment ()
	Smallest in/decrement is 1/256 (8 fract bits) = 0.00390625 in floating point.
*/
// pre-increment ++a: increases by 1 and returns reference to the modified object
Fixed& Fixed::operator++()
{
	this->_fixedValue += 1;
	return *this;
}

// pre-decrement --a: decreases by 1 and returns reference to the modified object
Fixed& Fixed::operator--()
{
	this->_fixedValue -= 1;
	return *this;
}

// post-increment a++: saves current state, increments, returns old state
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_fixedValue += 1;
	return temp;
}

// post-decrement a--: saves current state, decrements, returns old state
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_fixedValue -= 1;
	return temp;
}

/* Static Min and Max Functions */
// Returns a reference to the smaller of two modifiable Fixed objects
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

// Returns a reference to the larger of two modifiable Fixed objects
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

// Returns a reference to the smaller of two const Fixed objects
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

// Returns a reference to the larger of two const Fixed objects
const Fixed& Fixed::max(const Fixed& a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}