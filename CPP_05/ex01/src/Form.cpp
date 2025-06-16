#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/color.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << CYAN << "[Form] Default constructor was called for: " << _name << RESET << std::endl;
}

Form::Form(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _isSigned(false), _gradeToSign(signGrade), _gradeToExecute(executeGrade)
{
	std::cout << BLUE << "[Form] Default Name constructor was called for: " << _name << RESET << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& copy)
	: _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << MAGENTA << "[Form] Copy constructor was called for: " << _name << std::endl;
}

Form& Form::operator=(const Form& assign)
{
	std::cout << GREEN << "[Form] Assign constructor was called for: " << _name << RESET << std::endl;
	if (this != &assign)
	{
		_isSigned = assign._isSigned; // Others are const, so can't assign.
	}
	return *this;
}

Form::~Form()
{
	std::cout << RED << "[Form] Destructor was called for: " << _name << RESET << std::endl;
}

// Getters and Setters
const std::string& Form::getName() const
{
	return this->_name;
}

bool Form::isSigned() const
{
	return this->_isSigned;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

// Check if Form can be signed and will check the Bureaucrat's grade
void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;	
}

// Execptions
const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low!";
}

// Operator << overload
std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form " << f.getName()
	   << " - [Signed: " << (f.isSigned() ? "Yes" : "No") << "] \n"
	   << "Grade to sign: " << f.getGradeToSign() << "\n" 
	   << "Grade to execute: " << f.getGradeToExecute() << std::endl;
	return os;
}