#pragma once

#include <string>
#include <iostream>
#include "color.hpp"

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