#pragma once

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"
#include "color.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& copy);
		WrongCat& operator=(const WrongCat& assign);
		~WrongCat();

		void makeSound() const;
};