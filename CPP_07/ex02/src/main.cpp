#include "../include/Array.hpp"
#include <iostream>
#include <string>
#include <exception>

int main()
{
	std::cout << "----- Default constructor test -----" << std::endl;
	Array<int> empty;
	std::cout << "empty.size() = " << empty.size() << std::endl;

	std::cout << "Trying to access empty[0]:" << std::endl;
	try
	{
		std::cout << empty[0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n----- Sized int array test -----" << std::endl;
	Array<int> numbers(5);
	std::cout << "numbers.size() = " << numbers.size() << std::endl;

	// Manually setting values, b/o default initialization.
	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;

	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

	std::cout << "\n----- Out-of-bounds test -----" << std::endl;
	std::cout << "Trying to access numbers[10]:" << std::endl;
	try
	{
		std::cout << numbers[10] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n----- Copy constructor deep copy test -----" << std::endl;
	Array<int> copy(numbers);
	std::cout << "Created array numbers, which made a deep copy of array copy." << std::endl;

	std::cout << "Before modification:" << std::endl;
	std::cout << "numbers[0] = " << numbers[0] << std::endl;
	std::cout << "copy[0] = " << copy[0] << std::endl;

	numbers[0] = 999;

	std::cout << "After modifying original:" << std::endl;
	std::cout << "numbers[0] = " << numbers[0] << std::endl;
	std::cout << "copy[0] = " << copy[0] << std::endl;

	std::cout << "\n----- Assignment operator deep copy test -----" << std::endl;
	Array<int> assigned(3);
	// setting each element to -1
	for (unsigned int i = 0; i < assigned.size(); i++)
		assigned[i] = -1;

	assigned = numbers;

	std::cout << "Before modification:" << std::endl;
	std::cout << "numbers[1] = " << numbers[1] << std::endl;
	std::cout << "assigned[1] = " << assigned[1] << std::endl;

	numbers[1] = 555;

	std::cout << "After modifying original:" << std::endl;
	std::cout << "numbers[1] = " << numbers[1] << std::endl;
	std::cout << "assigned[1] = " << assigned[1] << std::endl;

	std::cout << "\n----- Const access [] test -----" << std::endl;
	const Array<int> constNumbers(numbers);
	for (unsigned int i = 0; i < constNumbers.size(); i++)
		std::cout << "constNumbers[" << i << "] = " << constNumbers[i] << std::endl;

	std::cout << "\n----- String array test -----" << std::endl;
	Array<std::string> words(3);
	words[0] = "CPP";
	words[1] = "ex02";
	words[2] = "Array";

	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << "words[" << i << "] = " << words[i] << std::endl;
	
	std::cout << "\n----- Const string array test -----" << std::endl;
	const Array<std::string> constWords(words);
	for (unsigned int i = 0; i < constWords.size(); i++)
	std::cout << "constWords[" << i << "] = " << constWords[i] << std::endl;

	return 0;
}