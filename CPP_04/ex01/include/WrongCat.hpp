#pragma once

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"
#include "color.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal
{
	private:
		Brain* brain;

	public:
		WrongCat();
		WrongCat(const WrongCat& copy);
		WrongCat& operator=(const WrongCat& assign);
		~WrongCat();

		void makeSound() const;
		
		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
		Brain* getBrain() const;
};