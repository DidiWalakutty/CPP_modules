#pragma once

#include "AForm.hpp"
#include "color.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	private:
		const std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& assign);
		~RobotomyRequestForm();

		void executeFormAction() const override;
};