#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << CYAN << "[Bureaucrat] Default constructor was called for: " << _name << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	std::cout << YELLOW << "[Bureaucrat] Default Name constructor was called for: " << _name << RESET << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << MAGENTA << "[Bureaucrat] Copy constructor was called for: " << _name << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& assign)
{
	std::cout << GREEN << "[Bureaucrat] Assign constructor was called for: " << _name << RESET << std::endl;
	if (this != &assign)
	{
		_grade = assign._grade; // _name is const, so can't assign that.
		std::cout << UNDERLINE << "Grade updated to match " << assign._name
		          << ": now grade " << _grade << RESET << std::endl;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "[Bureaucrat] Destructor was called for: " << _name << RESET << std::endl;
}

// Getters
const std::string& Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

// Change grades
void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

// Exception Messages
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

// Operator << overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}

// Sign Form
void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}