#include "../include/WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << GREEN << "WrongCat's Default constructor was called." << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << GREEN << "WrongCat's Copy constructor was called." << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& assign)
{
	std::cout << GREEN << "WrongCat's Assign constructor was called." << RESET << std::endl;
	if (this != &assign)
	{
		WrongAnimal::operator=(assign);
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << BG_RED << "WrongCat's Destructor was called." << RESET << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << GREEN << "WrongCat's makes a wrong MEOW sound..." << RESET << std::endl;
}