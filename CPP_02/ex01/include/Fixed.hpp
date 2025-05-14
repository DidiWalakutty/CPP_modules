#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _rawBits;
		static const int _fractBits = 8;
	
	public:
		Fixed();						// Default constructor
		Fixed(const int fixedInt);		// Int constructor
		Fixed(const float fixedFloat);	// Float constructor
		Fixed(const Fixed& copy);		// Copy constructor
		Fixed& operator=(const Fixed& Assign); // Copy assignment operator
		~Fixed();						// Destructor

		float	toFloat() const;
		int		toInt() const;

		// for testing
		int getRawBits() const;
};

// Overloads operator<< to print a Fixed object, converting it to an int or float.
// Tells the compiler how to print a Fixed object when used with std::cout.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif