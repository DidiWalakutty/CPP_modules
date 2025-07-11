#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "color.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int	_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& assign);
		~Bureaucrat();

		const std::string& getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(AForm& form);
		void executeForm(AForm const& form) const;
		
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const noexcept;
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const noexcept;
		};
};

// Overload <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);