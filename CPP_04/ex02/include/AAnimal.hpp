#pragma once

#include <iostream>
#include "../include/color.hpp"

/* 	= 0: Pure virtual function — it now must be overridden in derived classes.
		Enables polymorphism: calls the right function at runtime based on object type.
 		Makes the class abstract: you can't do AAnimal a; but AAnimal* a = new Dog(); is fine.
		This supports runtime polymorphism.
		Because it's now a pure virtual funct., we don't implement it in the .cpp
*/
 class AAnimal
{
	protected:
		std::string type;

	public:
		AAnimal();
		AAnimal(const AAnimal& copy);
		AAnimal& operator=(const AAnimal& assign);
		virtual ~AAnimal();

		virtual void makeSound() const = 0;
		std::string getType() const;
};