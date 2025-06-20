#pragma once

#include "AForm.hpp"
#include "color.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

// 'using' is a type alias, which creates a new name (alias) for a complicated
// function pointer type, so the code is easier to read/write.
// This isn't the same as "using namespace", which makes all names in a namespace
// available without the namespace prefix (like std::string).
class Intern
{
	private:
		// Pointer to a function that takes a const string reference and returns a pointer to an AForm.
		using FormFn = AForm* (*)(const std::string& target);
		static const FormFn  formFn[3];
		static const std::string formType[3];

		static AForm *createPresidentForm(const std::string& target);
		static AForm *createRobotForm(const std::string& target);
		static AForm *createShrubberyForm(const std::string& target);

	public:
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& assign);
		~Intern();

		AForm *makeForm(const std::string &formName, const std::string &formTarget);
};
