#include "../include/Convert.hpp"


void convertChar(const std::string& str)
{

}

void ScalarConverter::convert(const std::string& input)
{
	// 1. Detect Type
	c_type type = detectType(input);

	switch (type)
	{
		case CHAR:
			convertChar(input);
			break;
		case INT:
			converInt(input);
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