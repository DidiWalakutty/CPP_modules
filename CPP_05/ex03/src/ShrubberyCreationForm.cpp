#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : 
	AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	std::cout << CYAN << "[Shrubbery] Default constructor was called for: " << _target << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << YELLOW << "[Shrubbery] Default Name constructor was called for: " << _target << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) :
	AForm(copy), _target(copy._target)
{
	std::cout << MAGENTA << "[Shrubbery] Copy constructor was called for: " << _target << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& assign)
{
	std::cout << GREEN << "[Shrubbery] Assign constructot was called for: " << _target << RESET << std::endl;
	if (this != &assign)
	{
		AForm::operator=(assign);
		_target = assign._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "[Shrubbery] Destructor was called for: " << _target << RESET << std::endl;
}

void ShrubberyCreationForm::executeFormAction() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename);

	if (!outfile)
	{
		std::cerr << "Error: Could not open file: " << filename << std::endl;
		return;
	}
	outfile << 
	"      ~ ~ ~ ~ ~ 🌱🌿🌸🌿🌱 ~ ~ ~ ~ ~\n"
	"       _-_\n"
	"    /~~   ~~\\\n"
	" /~~         ~~\\\n"
	"{     ASCII      }\n"
	" \\  _-     -_  /\n"
	"   ~  \\\\ //  ~\n"
	"_- -   | | _- _\n"
	"  _ -  | |   -_\n"
	"      // \\\\\n"
	"      ~ ~ ~ ~ ~ 🌱🌿🌸🌿🌱 ~ ~ ~ ~ ~\n";;
	outfile.close();
	std::cout << BG_GREEN << "Shrubbery has been planted in file: " << filename << RESET << std::endl;
}