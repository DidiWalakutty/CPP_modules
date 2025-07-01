#include "../include/Convert.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong usage: ./convert <literal>" << std::endl;
		return (1); 
	}
	
	std::string input = argv[1];
	if (input.empty())
	{
		std::cerr << "Input is empty" << std::endl;
	}

	ScalarConverter::convert(input);
	// try
	// {
	// 	ScalarConverter::convert(argv[1]);
	// }
	// catch (const std::exception& e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// 	return (1); 
	// }
	return (0);
}