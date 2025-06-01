#include "../include/Animal.hpp"

Animal::Animal() 
{
	this->type = "Animal";
	std::cout << YELLOW << "[Animal] Default constructor was called." << RESET << std::endl;
}

Animal::Animal(const Animal& copy) : type(copy.type)
{
	std::cout << YELLOW << "[Animal] Copy constructor was called." << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& assign)
{
	std::cout << YELLOW << "[Animal] Assign constructor was called." << RESET << std::endl;
	if (this != &assign)
	{
		this->type = assign.type;
	}
	std::cout << YELLOW << "- [Assign] - type is now: " << type << RESET << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << BG_RED << "[Animal] Destructor was called." << RESET << std::endl;
}

void Animal::makeSound() const
{
	std::cout << MAGENTA << "[Animal] sighs, and emits a confused squeak..." << RESET << std::endl;
}

std::string Animal::getType() const
{
	return type;
}