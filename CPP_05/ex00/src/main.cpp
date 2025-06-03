#include "../include/Bureaucrat.hpp"

int main() 
{
	// Test 1
	std::cout << BG_GREEN << "---- Test 1: Valid Bureaucrat----" << RESET << std::endl;
	try 
	{
		Bureaucrat b1("Didi", 42);
		std::cout << b1 << std::endl;

		b1.incrementGrade();
		std::cout << "After increment: " << b1 << std::endl;

		b1.decrementGrade();
		std::cout << "After decrement: " << b1 << std::endl;
	}
	catch (std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test 2
	std::cout << std::endl;
	std::cout << BG_GREEN << "---- Test 2: Too High Grade ----" << RESET << std::endl;
	try 
	{
		Bureaucrat b2("TooHigh", 0);
	}
	catch (std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test 3
	std::cout << std::endl;
	std::cout << BG_GREEN << "---- Test 3: Too Low Grade ----" << RESET << std::endl;
	try 
	{
		Bureaucrat b3("TooLow", 151);
	}
	catch (std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test 4
	std::cout << std::endl;
	std::cout << BG_GREEN << "---- Test 4: Increment Over Limit ----" << RESET << std::endl;
	try 
	{
		Bureaucrat top("TopDog", 1);
		std::cout << top << std::endl;
		top.incrementGrade();
	}
	catch (std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test 5
	std::cout << std::endl;
	std::cout << BG_GREEN << "---- Test 5: Decrement Over Limit ----" << RESET << std::endl;
	try 
	{
		Bureaucrat low("BottomFeeder", 150);
		std::cout << low << std::endl;
		low.decrementGrade();
	}
	catch (std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test 6
	std::cout << std::endl;
	std::cout << BG_GREEN << "---- Test 6: Copy & Assign Constructors ----" << RESET << std::endl;
	try
	{
		std::cout << BLUE << "Default name constructor:" << RESET << std::endl;
		Bureaucrat original("original", 20);
		std::cout << std::endl;

		std::cout << BLUE << "Copy name constructor:" << RESET << std::endl;
		Bureaucrat copy(original);
		std::cout << std::endl;

		std::cout << BLUE << "Assign constructor:" << RESET << std::endl;
		Bureaucrat test("test", 2);
		std::cout << test << std::endl;
		test = original;
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
