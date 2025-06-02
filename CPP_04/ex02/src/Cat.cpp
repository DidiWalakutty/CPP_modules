#include "../include/Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << CYAN << "[Cat] Default constructor was called." << RESET << std::endl;
	this->brain = new Brain();
}

Cat::Cat (const Cat& copy) : AAnimal(copy)
{
	std::cout << CYAN << "[Cat] Copy constructor was called." << RESET << std::endl;
	this->brain = new Brain(*copy.brain);
}

Cat& Cat::operator=(const Cat& assign)
{
	std::cout << CYAN << "[Cat] Assign constructor was called." << RESET << std::endl;
	if (this != &assign)
	{
		AAnimal::operator=(assign);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*assign.brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << BG_RED << "[Cat] Destructor was called." << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << CYAN << "[Cat] sounds a purrrfect: meow!" << RESET << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return brain->getIdea(index);
}

Brain* Cat::getBrain() const
{
	return this->brain;
}