#include "../include/Convert.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong usage, use: ./convert <literal>" << std::endl;
		return (1); 
	}
	
	std::string input = argv[1];
	if (input.empty())
	{
		std::cerr << "Input is empty" << std::endl;
	}

	ScalarConverter::convert(input);
	return (0);
}