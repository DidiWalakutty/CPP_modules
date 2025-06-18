#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/color.hpp"

/*
	Because the executeFormAction() is a pure virtual function,
	we don't need to implement it in this .cpp
*/

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << CYAN << "[AForm] Default constructor was called for: " << _name << RESET << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _isSigned(false), _gradeToSign(signGrade), _gradeToExecute(executeGrade)
{
	std::cout << BLUE << "[AForm] Default Name constructor was called for: " << _name << RESET << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& copy)
	: _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << MAGENTA << "[AForm] Copy constructor was called for: " << _name << std::endl;
}

AForm& AForm::operator=(const AForm& assign)
{
	std::cout << GREEN << "[AForm] Assign constructor was called for: " << _name << RESET << std::endl;
	if (this != &assign)
	{
		_isSigned = assign._isSigned; // Others are const, so can't assign.
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << RED << "[AForm] Destructor was called for: " << _name << RESET << std::endl;
}

// Getters and Setters
const std::string& AForm::getName() const
{
	return this->_name;
}

bool AForm::isSigned() const
{
	return this->_isSigned;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

// Check if AForm can be signed and will check the Bureaucrat's grade
void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;	
}

/*
	This function checks if the form is signed and if the Bureaucrat's 
	execute grade is high enough. If so, it'll execute the action for that form.
*/
void AForm::execute(const Bureaucrat& executor) const
{
	if (!this->_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
	this->executeFormAction();
}

// Execptions
const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Aform is unsigned!";
}

// Operator << overload
std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm " << f.getName()
	   << " - [Signed: " << (f.isSigned() ? "Yes" : "No") << "] \n"
	   << "Grade to sign: " << f.getGradeToSign() << "\n" 
	   << "Grade to execute: " << f.getGradeToExecute() << std::endl;
	return os;
}