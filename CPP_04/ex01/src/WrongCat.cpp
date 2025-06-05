#include "../include/WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << GREEN << "[WrongCat] Default constructor was called." << RESET << std::endl;
	this->brain = new Brain();
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << GREEN << "[WrongCat] Copy constructor was called." << RESET << std::endl;
	this->brain = new Brain(*copy.brain);
}

WrongCat& WrongCat::operator=(const WrongCat& assign)
{
	std::cout << GREEN << "[WrongCat] Assign constructor was called." << RESET << std::endl;
	if (this != &assign)
	{
		WrongAnimal::operator=(assign);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*assign.brain);
	}
	return *this;
}

WrongCat::~WrongCat()
{
	delete this->brain;
	std::cout << BG_RED << "[WrongCat] Destructor was called." << RESET << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << GREEN << "[WrongCat] makes a wrong MEOW sound..." << RESET << std::endl;
}

void WrongCat::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}

std::string WrongCat::getIdea(int index) const
{
	return brain->getIdea(index);
}

Brain* WrongCat::getBrain() const
{
	return this->brain;
}