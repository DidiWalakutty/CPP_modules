#pragma once

#include "WrongAnimal.hpp"
#include "color.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& copy);
		WrongCat& operator=(const WrongCat& assign);
		~WrongCat();

		void makeSound() const;
};