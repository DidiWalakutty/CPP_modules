#pragma once

#include <iostream>
#include "color.hpp"
#include <string>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal& operator=(const WrongAnimal& assign);
		~WrongAnimal();
	
		std::string getType() const;
		void makeSound() const;
};