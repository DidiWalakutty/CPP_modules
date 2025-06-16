#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << CYAN << "Default constructor was called for: " << _name << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << YELLOW << "Default Name constructor was called for: " << _name << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << MAGENTA << "Copy constructor was called for: " << _name << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& assign)
{
	std::cout << GREEN << "Assign constructor was called for: " << _name << RESET << std::endl;
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
	std::cout << RED << "Destructor was called for: " << _name << RESET << std::endl;
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

// Exception Messages: where what() gets overridden
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