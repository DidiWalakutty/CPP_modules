#include "../include/Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << GREEN << "[Dog] Constructor was called." << RESET << std::endl;
	this->brain = new Brain();
}

/*
	We dereference the pointer (copy.brain) using *copy.brain to access
	the actual Brain object it points to — not just the address.

	Then, we pass that Brain object into the Brain copy constructor to 
	create a full copy (clone) of the original Brain.
*/
Dog::Dog (const Dog& copy) : AAnimal(copy)
{
	std::cout << GREEN << "[Dog] Copy constructor was called." << RESET << std::endl;
	this->brain = new Brain(*copy.brain); // deep copy of Brain: dereference the pointer so it's the actual Brain object.
}

Dog& Dog::operator=(const Dog& assign)
{
	std::cout << GREEN << "[Dog] Assign constructor was called." << RESET << std::endl;
	if (this != &assign)
	{
		AAnimal::operator=(assign);	// Copy base class part
		if (this->brain)			// If the current obj already has a brain, we must delete it b/o memory leaks 
			delete this->brain;
		this->brain = new Brain(*assign.brain); // Deep Copy: make a new copy of the other Dog's brain.
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

/*
	Call Brain's setIdea.
*/
void Dog::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);	// brain is a pointer to the Dog's own Brain object
}

std::string Dog::getIdea(int index) const
{
	return brain->getIdea(index);
}

Brain* Dog::getBrain() const
{
	return this->brain;
}