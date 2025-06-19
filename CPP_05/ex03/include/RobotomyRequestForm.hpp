#pragma once

#include "AForm.hpp"
#include "color.hpp"
#include <string>
#include <cstdlib>	// for randomization: rand() and srand()
#include <ctime>	// for time()

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& assign);
		~RobotomyRequestForm();

		void executeFormAction() const override;
};