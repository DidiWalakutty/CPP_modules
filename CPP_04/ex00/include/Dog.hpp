#pragma once

#include "../include/Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& assign);
		~Dog();

		void makeSound() const override;
};