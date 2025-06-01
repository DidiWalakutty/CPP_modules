#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << MAGENTA << "WrongAnimal's Default constructor was called." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	type = copy.type;
	std::cout << MAGENTA << "WrongAnimal's Copy constructor was called." << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& assign)
{
	std::cout << MAGENTA << "WrongAnimal's Assign constructor was called." << RESET << std::endl;
	if (this != &assign)
	{
		type = assign.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BG_RED << "WrongAnimal's destructor was called." << RESET << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << MAGENTA << "WrongAnimal makes a generic creepy sound..." << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}