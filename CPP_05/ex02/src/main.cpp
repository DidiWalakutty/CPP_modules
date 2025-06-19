#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(nullptr)); // ensures different outcomes for rand() each time the program runs
    std::cout << "\n=== FORM TESTING ===\n" << std::endl;

    try 
	{
        Bureaucrat darth("Darth Bureaucris", 1);
		std::cout << darth << std::endl;
        Bureaucrat bender("Bender", 45);
		std::cout << bender << std::endl;
        Bureaucrat jane("Janeway", 135);
		std::cout << jane << std::endl;
        Bureaucrat dave("Dave", 150);
		std::cout << dave << std::endl;
		std::cout << std::endl;

        // Create forms
        ShrubberyCreationForm shrubForm("Garden_of_Endor");
        RobotomyRequestForm robotForm("Roomba of Doom");
        PresidentialPardonForm pardonForm("Galactic Criminal");

        // --- Shrubbery Form ---
        std::cout << "\n--- ShrubberyCreationForm | 145 | 137 ---" << std::endl;
        jane.signForm(shrubForm);
        jane.executeForm(shrubForm);

        // // --- Robotomy Form ---
        std::cout << "\n--- RobotomyRequestForm | 72 | 45 ---" << std::endl;
        bender.signForm(robotForm);
        bender.executeForm(robotForm);

		// // Try to execute unsigned form (expect error)
        std::cout << "\n--- Try executing unsigned PardonForm ---" << std::endl;
        dave.executeForm(pardonForm);
		darth.executeForm(pardonForm);

		// // --- Presidential Pardon Form ---
        std::cout << "\n--- PresidentialPardonForm | 25 | 5 ---" << std::endl;
        darth.signForm(pardonForm);
        darth.executeForm(pardonForm);
    
        // --- Failure Case ---
        std::cout << "\n--- Try executing form with low-grade bureaucrat ---" << std::endl;
        dave.signForm(shrubForm);
        dave.executeForm(shrubForm);
		std::cout << std::endl;
    } 
	catch (const std::exception& e) 
	{
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
    return 0;
}
