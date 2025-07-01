#include "../include/Convert.hpp"

static bool check_char(const std::string& str)
{
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return true;
	return false;
}

/*
	Check if the string is a valid integer literal:
	- Optional leading '+' or '-' sign, digits only.
	- check if it fits int range after conversion with std::stoll.
	- std::stoll will throw exception if > long long or not a valid format type. 
*/
static bool check_int(const std::string& str)
{
	size_t i = 0;

	if (str[0] == '-' || str[0] == '+')
	{
		if (str.length() == 1)
			return false;
		i = 1;
	}
	for (;i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	
	try
	{
		long long input = std::stoll(str);
		if (input < std::numeric_limits<int>::min() || input > std::numeric_limits<int>::max())
			return false;
	}
	catch (const std::out_of_range& e)
	{
		return false;
	}
	catch (const std::invalid_argument& e)
	{
		return false;
	}
	return true;
}

static bool check_float(const std::string& str)
{
	if (str.size() == 1)
		return false;
	if (str.back() != 'f')
		return false;
	
	std::string validity = str.substr(0, str.length() - 1);
	try
	{
		std::stof(validity);
		return true;
	}
	catch (const std::exception& e)
	{
		return false;
	}
}

static bool check_double(const std::string& str)
{
	try
	{
		std::stod(str);
		return true;
	}
	catch (const std::exception& e)
	{
		return false;
	}
	

}

c_type detectType(const std::string& input)
{
	if (input == "+inf" || input == "-inf" || input == "nan")
		return (DOUBLE);
	if (input == "+inff" || input == "-inff" || input == "nanf")
		return (FLOAT);
	if (check_char(input))
		return (CHAR);
	if (check_int(input))
		return (INT);
	if (check_float(input))
		return (FLOAT);
	if (check_double(input))
		return (DOUBLE);
	return (INVALID);
}
