#pragma once

#include <iostream>
#include "../include/color.hpp"

/*
	Virtual Destructor: Ensures the derived class destructor is called correctly during delete.
						Like when you delete Animal* a = new Cat();
	Virtual Functions:  program checks at runtime what the real type is and calls that version's makeSound.
					    Enables runtime polymorphism (program calls the correct overridden function)
*/
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