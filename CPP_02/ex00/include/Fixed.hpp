#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

// Copy Constructor:
//   Fixed b(a); → creates a new object with same values as 'a'.
// Called when a new object is initialized from another.

// Copy Assignment Operator:
//   b = a; → overwrites values from 'a' into existing object 'b'.
// Called when assigning one object’s values to another.

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