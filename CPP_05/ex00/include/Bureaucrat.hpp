#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "color.hpp"

/*
	Exception classes (GradeTooHigh/GradeTooLow) inherit from 
	std::exception to enable error handling with try/catch.
	We override what() to return a custom error message that explains what went wrong.
	Catching by reference (std::exception& e) avoids copies and lets us access that message directly.

	The const noexcept guarantees it won't throw additional exceptions.
*/
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

		// exceptions
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