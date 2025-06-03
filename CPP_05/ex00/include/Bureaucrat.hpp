#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "color.hpp"

/*
	Exception classes (GradeTooHighException / GradeTooLowException) inherit from std::exception,
	which lets them be caught with catch (std::exception& e).
	They override the what() method to return a message describing the error.
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

		const std::string& getname() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

// Overload <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);