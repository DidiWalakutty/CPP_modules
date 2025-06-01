#pragma once

#include <iostream>
#include "../include/color.hpp"

// Use virtual to enable runtime polymorphism (program calls the correct overridden function)
//
// Without a virtual destructor, the derived class destructor won't be called
// and will result in undefined behavior. This way the entire object will be destroyed.
class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& assign);
		virtual ~Animal();

		virtual void makeSound() const;
		std::string getType() const;
};