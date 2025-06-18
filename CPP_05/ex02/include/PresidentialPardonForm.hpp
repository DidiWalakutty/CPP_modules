#pragma once

#include "AForm.hpp"
#include "color.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& assign);
		~PresidentialPardonForm();

		void executeFormAction() const override;
};