#include "../include/Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << GREEN << "Dog's Constructor was called." << RESET << std::endl;
}

Dog::Dog (const Dog& copy) : Animal(copy)
{
	std::cout << GREEN << "Dog's Copy constructor was called." << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& assign)
{
	std::cout << GREEN << "Dog's Assign constructor was called." << RESET << std::endl;
	if (this != &assign)
	{
		Animal::operator=(assign);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << BG_RED << "Dog Destructor was called." << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << GREEN << "Dog sounds a pawdorable: woof!" << RESET << std::endl; 
}