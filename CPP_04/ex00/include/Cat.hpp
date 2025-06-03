#pragma once

#include "Animal.hpp"
#include <iostream>
#include <string>

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& assign);
		~Cat();

		void makeSound() const override;
};