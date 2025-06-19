#include "../include/color.hpp"
#include "../include/AForm.hpp"
#include "../include/Intern.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* form;
	Bureaucrat didi("Didi", 1);
	AForm* form2;
	std::cout << std::endl; 

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    delete form;
	std::cout << std::endl; 

    form = someRandomIntern.makeForm("presidential request", "Alice");
	didi.signForm(*form);
	didi.executeForm(*form);
    delete form;
	std::cout << std::endl; 

    form = someRandomIntern.makeForm("shrubbery request", "Garden");
    delete form;
	std::cout << std::endl; 

    form2 = someRandomIntern.makeForm("unknown form", "Nobody");  // should print error and return nullptr
    delete form2;  // safe even if nullptr

    return 0;
}
