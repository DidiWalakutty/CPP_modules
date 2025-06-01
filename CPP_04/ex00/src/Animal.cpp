#include "../include/Animal.hpp"

Animal::Animal() 
{
	this->type = "Animal";
	std::cout << YELLOW << "Animal's Default constructor was called." << RESET << std::endl;
}

Animal::Animal(const Animal& copy) : type(copy.type)
{
	std::cout << YELLOW << "Animal's Copy constructor was called." << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& assign)
{
	std::cout << YELLOW << "Animal's Assign constructor was called." << RESET << std::endl;
	if (this != &assign)
	{
		this->type = assign.type;
	}
	std::cout << YELLOW << "Animal's new type is: " << type << RESET << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << BG_RED << "Animal Destructor was called." << RESET << std::endl;
}

void Animal::makeSound() const
{
	std::cout << MAGENTA << "Animal sighs, and emits a confused squeak..." << RESET << std::endl;
}

std::string Animal::getType() const
{
	return type;
}