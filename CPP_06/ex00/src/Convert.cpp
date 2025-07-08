#include "../include/Convert.hpp"


void convertChar(char c)
{
	if (std::isprint(static_cast<unsigned char>(c)))	// cast to unsigned to avoid undefined behavior, ensures valid range of [0, 255]
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non Displayable" << std::endl;
	
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double" << static_cast<double>(c) << ".0" << std::endl; 
}

void convertInt(int i)
{
	// char: check if it's printable, and in char-range?
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(i)))
		std::cout << "char: Non Displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

	// we can print the i, because we checked if < int MIn or > int Max before.
	std::cout << "int: " << i << std::endl;
	// float: will always fit
	// double: will always fit
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void convertFloat(const std::string& input)
{
	float f;
	try
	{
		f = std::stof(input);
	}
	catch (const std::out_of_range&)
	{
		if (!input.empty() && input[0] == '-')
			f = -std::numeric_limits<float>::infinity();
		else
			f = std::numeric_limits<float>::infinity();
	}
	catch (const std::invalid_argument&)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	
	// if nan or infinite number, int and char are always impossible
	if (input == "nanf" || std::isnan(f))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (input == "+inff" || input == "-inff" || std::isinf(f)) 
	{
    	std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;

		if (f < 0) 
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		} 
		else 
		{
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
    	return;
	}
	
	// Check if char fits range and is printable
	if (f < static_cast<float>(std::numeric_limits<char>::min()) || f > static_cast<float>(std::numeric_limits<char>::max()))
		std::cout << "char: impossible" << std::endl;
	else
	{
		unsigned char c = static_cast<unsigned char>(f);
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non Displayable" << std::endl;
	}

	// Check if f fits in int range
	if (f < static_cast<float>(std::numeric_limits<int>::min()) || f > static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
	{
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	}

	// Check if we need .0f for fractional part, or just f
	if (f == static_cast<int>(f))
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	// Double output formatting with trailing '.0' if whole number
	double d = static_cast<double>(f);
	if (d == static_cast<int>(d))
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void convertDouble(const std::string& input)
{
	double d;
	try
	{
		d = std::stod(input);
	}
	catch (const std::out_of_range& e)
	{
		// Check if it's too big and should be treated as +inf or -inf
		if (!input.empty() && input[0] == '-')
			d = -std::numeric_limits<double>::infinity();
		else
			d = std::numeric_limits<double>::infinity();
	}
	catch (const std::exception& e)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	// Handle NaN
	if (input == "nan" || std::isnan(d))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}

	// Handle +inf / -inf from input OR overflow
	if (input == "+inf" || input == "-inf" || std::isinf(d))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (d < 0)
		{
			std::cout << "float: -inff\n";
			std::cout << "double: -inf" << std::endl;
		}
		else
		{
			std::cout << "float: +inff\n";
			std::cout << "double: +inf" << std::endl;
		}
		return;
	}

	// Convert to char
	if (d < static_cast<double>(std::numeric_limits<char>::min()) || d > static_cast<double>(std::numeric_limits<char>::max()))
		std::cout << "char: impossible" << std::endl;
	else
	{
		unsigned char c = static_cast<unsigned char>(d);
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non Displayable" << std::endl;
	}

	// Convert to int
	if (d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	// Convert to float
	if (d < static_cast<double>(std::numeric_limits<float>::lowest()) || d > static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "float: impossible" << std::endl;
	else
	{
		float f = static_cast<float>(d);
		if (f == static_cast<int>(f))
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}

	// Double output
	if (d == static_cast<int>(d))
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}


void ScalarConverter::convert(const std::string& input)
{
	// 1. Detect Type
	c_type type = detectType(input);

	switch (type)
	{
		case CHAR:
			convertChar(input[0]);
			break;
		case INT:
			convertInt(std::stoi(input));
			break;
		case FLOAT:
			convertFloat(input);
			break;
		case DOUBLE:
			convertDouble(input);
			break;
		case INVALID:
			std::cout << "Error: invalid literal" << std::endl;
			break;
	}
	// 2. Convert to detected type
	// 3. static_cast to other types
	// 4. print results.
}