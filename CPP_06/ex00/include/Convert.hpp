#pragma once

#include <iostream>
#include <limits>
#include <stdexcept>

typedef enum type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
}	c_type;

class ScalarConverter
{
	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& copy) = delete;
		ScalarConverter& operator=(const ScalarConverter& assign) = delete;
		~ScalarConverter();

	public:
		static void convert(const std::string& input);
};

c_type detectType(const std::string& input);

void convertChar(const std::string& str);
void convertInt(const std::string& str);
void convertFloat(const std::string& str);
void convertDouble(const std::string& str);