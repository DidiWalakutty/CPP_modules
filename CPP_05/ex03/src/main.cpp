#include "../include/AForm.hpp"
#include "../include/Intern.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
	std::cout << std::endl;
    AForm* form;
	AForm* form2;
    Intern someRandomIntern;
	std::cout << std::endl; 
	
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    delete form;
	std::cout << std::endl; 
	
	Bureaucrat didi("Didi", 1);
	std::cout << didi << std::endl;
    form = someRandomIntern.makeForm("presidential request", "Alice");
	didi.signForm(*form);
	didi.executeForm(*form);
    delete form;
	std::cout << std::endl; 

    form = someRandomIntern.makeForm("shrubbery request", "Garden");
    delete form;
	std::cout << std::endl; 

    form2 = someRandomIntern.makeForm("unknown form", "Nobody");  // should print error and return nullptr
    delete form2;  // safe, even if nullptr
	std::cout << std::endl; 

    return 0;
}
