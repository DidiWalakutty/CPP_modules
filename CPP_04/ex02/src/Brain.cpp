#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout << MAGENTA << "[Brain] Default Constructor was called." << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain& copy)
{
	std::cout << MAGENTA << "[Brain] Copy constructor was called." << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
}

Brain& Brain::operator=(const Brain& assign)
{
	std::cout << MAGENTA << "[Brain] Assign constructor was called." << RESET << std::endl;
	if (this != &assign)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = assign.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << BG_RED << "[Brain] Destructor was called." << RESET << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index < 0 || index >= 100)
	{
		std::cerr << BG_MAGENTA << "[Brain] Error: Index " <<index << " is out of bounds, idea was not created!" << RESET << std::endl;
		return ;
	}
	ideas[index] = idea;

}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	return "[Invalid index or Out of Bounds]";
}