#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _fixedValue;
		static const int _fractBits = 8;

	public:
		Fixed();						// Default
		Fixed(const int intValue);		// Int
		Fixed(const float floatValue);	// Float
		Fixed(const Fixed& copy);		// Copy
		Fixed& operator=(const Fixed& assign); // Assign
		~Fixed();

		// Comparison - returns true/false
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		// Arithmetic - creates new value w/o modifying og
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		/* Increment/Decrement - pre and post.
		Pre - returns a reference to the modified object
		Post - returns a copy of the og object, before internal modification */ 
		Fixed& operator++();	// Pre-increment = ++a
		Fixed& operator--();	// Pre-decrement = --a
		Fixed operator++(int);	// Post-increment = a++
		Fixed operator--(int);	// Post-decrement = a--;

		/* Static min/max functions - return references to avoid copying.
		Provide both modifiable and const versions for flexibility. */
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed &b);

		float	toFloat() const;
		int		toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif