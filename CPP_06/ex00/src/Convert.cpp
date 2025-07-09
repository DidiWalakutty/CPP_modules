#include "../include/Convert.hpp"

/*
	Cast to unsigned to avoid undefined behavior, ensures valid range of [0, 255].
	Add trailing .0(f), because it'll be a round number.	
*/

void convertChar(char c)
{
	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non Displayable" << std::endl;
	
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl; 
}

/*
	Convert integer to all scalar types:
	- Check if int fits in char range.
	- Checked if it's an int in check_int, so just print it.
	- Float and double always fit, print with ".0" suffix.
*/
void convertInt(int i)
{
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(i)))
		std::cout << "char: Non Displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

/*
  - Use std::stof, catch out_of_range (set +/-inf) and invalid_argument (string has no valid number).
  - Handle special float literals "nanf", "+inff", "-inff" explicitly.
  - For normal float values:
    * Print float with "f" suffix, adding ".0" if whole number.
    * Print corresponding double value, adding ".0" if whole number.
*/
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

	// Double with trailing '.0' if whole number
	double d = static_cast<double>(f);
	if (d == static_cast<int>(d))
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

/*
  - Use std::stod, catch out_of_range (set +/-inf) and invalid_argument (string has no valid number).
  - Handle special double literals: "nan", "+inf", "-inf" explicitly.
  - For normal double values:
    * Check if double fits within float range:
       - If not, print "float: impossible".
       - Else print float with "f" suffix, adding ".0" if whole number.
    * Print double with trailing ".0" if whole number.
*/
void convertDouble(const std::string& input)
{
	double d;
	try
	{
		d = std::stod(input);
	}
	catch (const std::out_of_range& e)
	{
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

	if (input == "nan" || std::isnan(d))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}

	// Handle +inf / -inf from input or overflow
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

	if (d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

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

	if (d == static_cast<int>(d))
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}


void ScalarConverter::convert(const std::string& input)
{
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
}