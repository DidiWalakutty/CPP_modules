#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public AAnimal
{
	private:
		Brain* brain;
	
	public:
		Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& assign);
		~Dog();

		void makeSound() const override;

		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
		Brain* getBrain() const; 
};