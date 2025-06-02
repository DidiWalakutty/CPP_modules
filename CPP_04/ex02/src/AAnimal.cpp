#include "../include/AAnimal.hpp"

AAnimal::AAnimal() 
{
	this->type = "AAnimal";
	std::cout << YELLOW << "[AAnimal] Default constructor was called." << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) : type(copy.type)
{
	std::cout << YELLOW << "[AAnimal] Copy constructor was called." << RESET << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& assign)
{
	std::cout << YELLOW << "[AAnimal] Assign constructor was called." << RESET << std::endl;
	if (this != &assign)
	{
		this->type = assign.type;
	}
	std::cout << YELLOW << "- [Assign] - type is now: " << type << RESET << std::endl;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << BG_RED << "[AAnimal] Destructor was called." << RESET << std::endl;
}

std::string AAnimal::getType() const
{
	return type;
}