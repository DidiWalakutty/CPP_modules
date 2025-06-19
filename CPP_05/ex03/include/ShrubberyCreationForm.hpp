#pragma once

#include "AForm.hpp"
#include "color.hpp"
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& assign);
		~ShrubberyCreationForm();

		void executeFormAction() const override;
};