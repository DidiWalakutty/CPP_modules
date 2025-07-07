#pragma once

#include <iostream>
#include <limits>
#include <stdexcept>
#include <cmath>
#include <iomanip>

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

void convertChar(char c);
void convertInt(int i);
void convertFloat(const std::string& input);
void convertDouble(const std::string& input);

void printChar(char c);