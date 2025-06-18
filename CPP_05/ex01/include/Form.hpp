#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "color.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;	// Forward declaration

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		Form();
		Form(const std::string& name, int signGrade, int executeGrade);
		Form(const Form& copy);
		Form& operator=(const Form& assign);
		~Form();

		const std::string& getName() const;
		bool isSigned() const;
		int	getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

// Overload << for printing Form info
std::ostream& operator<<(std::ostream& os, const Form& f);
