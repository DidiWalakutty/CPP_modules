#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << MAGENTA << "[WrongAnimal] Default constructor was called." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : type(copy.type)
{
	std::cout << MAGENTA << "[WrongAnimal] Copy constructor was called." << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& assign)
{
	std::cout << MAGENTA << "[WrongAnimal] Assign constructor was called." << RESET << std::endl;
	if (this != &assign)
	{
		type = assign.type;
	}
	std::cout << YELLOW << "- [Assign] - type is now: " << type << RESET << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BG_RED << "[WrongAnimal] destructor was called." << RESET << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << MAGENTA << "[WrongAnimal] makes a generic creepy sound..." << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}