#pragma once

#include "AForm.hpp"
#include "color.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& assign);
		~ShrubberyCreationForm();

		void executeFormAction() const override;
};