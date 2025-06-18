#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	std::cout << CYAN << "[President's] Default constructor was called for: " << _target << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << YELLOW << "[President's] Default Name constructor was called for: " << _target << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) :
	AForm(copy), _target(copy._target)
{
	std::cout << MAGENTA << "[President's] Copy constructor was called for: " << _target << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& assign)
{
	std::cout << GREEN << "[President's] Assign constructor was called for: " << _target << RESET << std::endl;
	if (this != &assign)
	{
		AForm::operator=(assign);
		_target = assign._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "[President's] Destructor was called for: " << _target << RESET << std::endl;
}

void PresidentialPardonForm::executeFormAction() const
{
	std::cout << _target << " was hereby pardoned by President Zaphod Beeblebrox!" << std::endl;
}