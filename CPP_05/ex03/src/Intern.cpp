#include "../include/Intern.hpp"

const Intern::FormFn Intern::formFn[3] = 
{
	Intern::createPresidentForm, 
	Intern::createRobotForm, 
	Intern::createShrubberyForm
};

const std::string Intern::formType[] = 
{
	"presidential request", "robotomy request", "shrubbery request"
};


Intern::Intern()
{
	std::cout << CYAN << "[Intern] Default constructor was called for an intern." << RESET << std::endl;
}

// Since there's nothing to copy, we return the same object.
Intern::Intern(const Intern& copy)
{
	std::cout << "[Intern] Copy constructor called." << std::endl;
	*this = copy;
}

// Explicitly ignores the input parameter and returns the current object.
Intern& Intern::operator=(const Intern& assign)
{
	std::cout << "[Intern] Assignment operator called." << std::endl;
	(void)assign;
	return *this;
}

Intern::~Intern()
{
	std::cout << RED << "[Intern] Deconstructor was called for an intern." << RESET << std::endl;
}

AForm* Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	for (int i = 0; i < 3; i++)
	{
		if (formType[i] == formName)
		{
			std::cout << GREEN << "Intern creates \"" << formName << "\"" << RESET << std::endl;
			return formFn[i](formTarget);
		}
	}
	std::cerr << RED << "Intern couldn't find the form: \"" << formName << "\"" << RESET << std::endl;
	return nullptr;
}

AForm* Intern::createPresidentForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}