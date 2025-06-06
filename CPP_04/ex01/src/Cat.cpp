#include "../include/Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << CYAN << "[Cat] Default constructor was called." << RESET << std::endl;
	this->brain = new Brain();
}

/*
	We dereference the pointer (copy.brain) using *copy.brain to access
	the actual Brain object it points to — not just the address.

	Then, we pass that Brain object into the Brain copy constructor to 
	create a full copy (clone) of the original Brain - Deep Copy.
*/
Cat::Cat (const Cat& copy) : Animal(copy)
{
	std::cout << CYAN << "[Cat] Copy constructor was called." << RESET << std::endl;
	this->brain = new Brain(*copy.brain);
}
Cat& Cat::operator=(const Cat& assign)
{
	std::cout << CYAN << "[Cat] Assign constructor was called." << RESET << std::endl;
	if (this != &assign)
	{
		Animal::operator=(assign);
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