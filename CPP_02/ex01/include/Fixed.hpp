#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

// _fixedValue stores the whole fixed-point number (int + fraction) as an integer.
// _fractBits is the number of bits reserved for the fractional (decimal) part.

// In fixed-point, numbers are stored in binary.
// Fixed-point math avoids floating-point overhead while keeping decimal precision.
class Fixed
{
	private:
		int _fixedValue;
		static const int _fractBits = 8;
	
	public:
		Fixed();
		Fixed(const int fixedInt);		// Int constructor
		Fixed(const float fixedFloat);	// Float constructor
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& copyAssign);	// Copy assignment operator:
													// Creates a temp Fixed object that goes out of scope after assignment.
		~Fixed();

		float	toFloat() const;
		int		toInt() const;
};

// Overloads operator<< to print a Fixed class object, converting it to an int or float.
// Tells the compiler how to print a Fixed object when used with std::cout.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif