#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << CYAN << "[Robotomy] Default constructor was called for: " << _target << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << YELLOW << "[Robotomy] Default name constructor was called for: " << _target << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) :
	AForm(copy), _target(copy._target)
{
	std::cout << MAGENTA << "[Robotomy] Copy constructor was called for: " << _target << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& assign)
{
	std::cout << GREEN << "[Robotomy] Assign constructor was called for: " << _target << RESET << std::endl;
	if (this != &assign)
	{
		AForm::operator=(assign);
		_target = assign._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "[Robotomy] Destructor was called for: " << _target << RESET << std::endl;
}

void RobotomyRequestForm::executeFormAction() const
{
	std::cout << "Robotomy in progress: making drilling noises..." << std::endl;

	if (std::rand() % 2 == 0)
	{
		std::cout << BG_GREEN << "Robotomy was successfully executed on " << _target << RESET << std::endl;
	}
	else
	{
		std::cout << BG_GREEN << "Robotomy was unsuccessful on " << _target << RESET << std::endl;
	}
}