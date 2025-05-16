#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

// Copy Constructor:
//   Fixed b(a); → creates a new object as a copy of an existing one
//                 and duplicates that data from 'a'.

// Copy Assignment Operator:  
//   b = a; → overwrites values from 'a' into existing object 'b'.
// Fixed&: Returns a reference so assignments can be chained (e.g., a = b = c)

// Overloading: gives multiple functions/operators the same name, but different behavior
//              depending on their parameters.
class Fixed
{
	private:
		int	_fixedValue;
		static const int _fractBits = 8;
	
	public:
		Fixed();                   // Default Constructor
		Fixed(const Fixed& copy); // Copy Constructor
		Fixed& operator=(const Fixed& copyAssign); // Copy assignment operator, '=' is overloading
		~Fixed();                  // Deconstructor

		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif