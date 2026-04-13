/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 18:08:02 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/14 01:27:51 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &dataFile)
{
	loadCSV(dataFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	_exchangeRates = copy._exchangeRates;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	if (this != &assign)
	{
		_exchangeRates = assign._exchangeRates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() 
{
	// std::cout << MAGENTA << "BitcoinExchange object destroyed." << RESET << std::endl;
}


/**
 *  @brief Loads and validates exchange rates from a CSV file.
 * 
 *  Parses "YYYY-MM-DD,rate" lines into the _exchangeRates map.
 *  Validates file format, date correctness and non-negative exchange rates.
 */
void BitcoinExchange::loadCSV(const std::string& dataFile)
{
	if (dataFile.empty())
		throw std::runtime_error("Data file path is empty.");
	
	size_t dotPos = dataFile.find_last_of('.');
	if (dotPos == std::string::npos || dataFile.substr(dotPos + 1) != "csv")
		throw std::runtime_error("Data file must have a .csv extension.");

	std::ifstream file(dataFile);
	if (!file.is_open())
		throw std::runtime_error("Failed to open data file: " + dataFile);
	
	// Skip header line and check if file is empty
	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Data file is empty: " + dataFile);
	
	while (std::getline(file, line))
	{
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			throw std::runtime_error("Invalid CSV format: missing comma in line: " + line);
		
		// Extract date and exchange rate
		std::string date = trim(line.substr(0, commaPos));
		std::string exchangeRate = trim(line.substr(commaPos + 1));
		if (date.empty() || exchangeRate.empty())
			throw std::runtime_error("Invalid CSV format: empty date or exchange rate in line: " + line);

		// Validate date format and exchange rate
		if (!isValidDate(date))
			throw std::runtime_error("Invalid date format in CSV: " + date);
		
		double rate;
		try {
			rate = std::stod(exchangeRate); // Convert to double because of decimal points
			_exchangeRates[date] = rate;
		}
		catch (const std::exception &e)
		{
			throw std::runtime_error("Invalid exchange rate in CSV: " + exchangeRate);
		}
		if (rate < 0)
			throw std::runtime_error("Exchange rate cannot be negative in CSV: " + exchangeRate);
	}
	if (_exchangeRates.empty())
		throw std::runtime_error("No valid exchange rates found in data file: " + dataFile);
}

void BitcoinExchange::processInputFile(const std::string &inputFile)
{
	if (inputFile.empty())
		throw std::runtime_error("Input file path is empty.");

	size_t dotPos = inputFile.find_last_of('.');
	if (dotPos == std::string::npos || inputFile.substr(dotPos + 1) != "txt")
		throw std::runtime_error("Input file must have a .txt extension.");

	std::ifstream file(inputFile);
	if (!file.is_open())
		throw std::runtime_error("Failed to open input file: " + inputFile);

	// Skip header line and check if file is empty
	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Input file is empty: " + inputFile);

	while (std::getline(file, line))
	{
		// 1. Trim whitespace from the line
		line = trim(line);
		if (line.empty())
			continue; // Skip empty lines

		// 2. Validate its format (similar to CSV but with " | " separator)
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cout << RED << "Invalid input format: missing pipe separator in line: " << line << RESET << std::endl;
			continue;
		}

		// 3. Extract date and value, trimming whitespace
		std::string date = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 1));
		if (date.empty() || valueStr.empty())
		{
			std::cout << RED << "Invalid input format: empty date or value in line: " << line << RESET << std::endl;
			continue;
		}

		// 4. Validate date
		if (!isValidDate(date))
		{
			std::cout << RED << "Invalid date format in input: " << date << RESET << std::endl;
			continue;
		}

		// 5. Validate value
		double value;
		try {
			value = std::stod(valueStr);
		}
		catch (const std::exception &e)
		{
			std::cout << RED << "Invalid value in input: " << valueStr << RESET << std::endl;
		}
		if (value < 0)
			std::cout << RED << "Value cannot be negative in input: " << valueStr << RESET << std::endl;
		if (value > 1000)
			std::cout << RED << "Value cannot be greater than 1000 in input: " << valueStr << RESET << std::endl;
			
		// 6. Look up exchange rate for the date (or closest previous date)
		double rate = getExchangeRateForDate(date);
		// check rate?
		double result = value * rate;

		// 7. Print results or errors for each line
		
	}
	// 4. Validate date and value
	// 5. Look up exchange rate for the date (or closest previous date) 
	// 6. calculate value * rate
	// 7. Print results or errors for each line
}