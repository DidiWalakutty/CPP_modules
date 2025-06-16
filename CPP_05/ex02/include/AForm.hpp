#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "color.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		AForm();
		AForm(const std::string& name, int signGrade, int executeGrade);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& assign);
		~AForm();

		const std::string& getName() const;
		bool isSigned() const;
		int	getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& b);

		//expections
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

// Overload << for printing AForm info
std::ostream& operator<<(std::ostream& os, const AForm& f);
