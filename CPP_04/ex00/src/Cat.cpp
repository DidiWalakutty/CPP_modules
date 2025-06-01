#include "../include/Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << CYAN << "Cat's Default constructor was called." << RESET << std::endl;
}

Cat::Cat (const Cat& copy) : Animal(copy)
{
	std::cout << CYAN << "Cat's Copy constructor was called." << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& assign)
{
	std::cout << CYAN << "Cat's Assign constructor was called." << RESET << std::endl;
	if (this != &assign)
	{
		Animal::operator=(assign);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << BG_RED << "Cat Destructor was called." << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << CYAN << "Cat sounds a purrrfect: meow!" << RESET << std::endl;
}