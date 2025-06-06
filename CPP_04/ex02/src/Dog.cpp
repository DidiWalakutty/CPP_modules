#include "../include/Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << GREEN << "[Dog] Constructor was called." << RESET << std::endl;
	this->brain = new Brain();
}

Dog::Dog (const Dog& copy) : AAnimal(copy)
{
	std::cout << GREEN << "[Dog] Copy constructor was called." << RESET << std::endl;
	this->brain = new Brain(*copy.brain);
}

Dog& Dog::operator=(const Dog& assign)
{
	std::cout << GREEN << "[Dog] Assign constructor was called." << RESET << std::endl;
	if (this != &assign)
	{
		AAnimal::operator=(assign);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*assign.brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << BG_RED << "[Dog] Destructor was called." << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << GREEN << "[Dog] sounds a pawdorable: woof!" << RESET << std::endl; 
}

void Dog::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return brain->getIdea(index);
}

Brain* Dog::getBrain() const
{
	return this->brain;
}