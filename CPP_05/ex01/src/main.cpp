#include <iostream>
#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main() 
{
	std::cout << std::endl;
	std::cout << BG_GREEN << "--- Test 1: Regular testing ---" << RESET << std::endl;
	std::cout << std::endl;
    try 
	{
        Bureaucrat maleficent("Maleficent", 2);
        Bureaucrat bob("Billy Bob", 45);
		std::cout << std::endl;

        Form taxForm("Tax Return", 45, 30);
        Form secretDoc("Top Secret", 2, 1);
		Form bossDoc("Boss doc", 1, 1);

        std::cout << "\n--- Initial State ---\n";
        std::cout << maleficent << std::endl;
        std::cout << bob << std::endl;
		std::cout << std::endl;
        std::cout << taxForm << std::endl;
        std::cout << secretDoc << std::endl;
		std::cout << bossDoc << std::endl;

        std::cout << "--- Signing Attempts ---\n";
        maleficent.signForm(taxForm);
        bob.signForm(taxForm);
        maleficent.signForm(secretDoc);
        bob.signForm(secretDoc);
		maleficent.signForm(bossDoc);
		bob.signForm(bossDoc);

        std::cout << "\n--- Final State ---\n";
        std::cout << taxForm << std::endl;
        std::cout << secretDoc << std::endl;
		std::cout << bossDoc << std::endl;
    }
    catch (std::exception& e) 
	{
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }

	std::cout << std::endl;
	std::cout << BG_GREEN << "--- Test 2: Assign testing ---" << RESET << std::endl;
	try 
	{
		Bureaucrat alice("Alice", 42);
		Bureaucrat bob("Bob", 10);

		std::cout << "\n--- Before assignment ---" << std::endl;
		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << std::endl;

		// Assignment test: assign bob to alice
		alice = bob;

		std::cout << "\n--- After assignment (alice = bob) ---" << std::endl;
		std::cout << "Alice: " << alice << std::endl;
		std::cout << "Bob: " << bob << std::endl;
		std::cout << std::endl;

		// Create a form
		Form passportForm("Passport Form", 20, 10);
		std::cout << "\n--- Form info ---" << std::endl;
		std::cout << passportForm << std::endl;

		// Try signing the form
		alice.signForm(passportForm);  // will succeed if grade <= 20
		std::cout << std::endl;
	} 
	catch (std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
    return 0;
}
