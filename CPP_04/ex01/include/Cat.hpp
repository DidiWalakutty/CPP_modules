#pragma once

#include "../include/Animal.hpp"
#include "../include/Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* brain;
	
	public:
		Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& assign);
		~Cat();

		void makeSound() const override;

		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
		Brain* getBrain() const;
};