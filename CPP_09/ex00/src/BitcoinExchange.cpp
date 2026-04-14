/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 18:08:02 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/14 17:17:21 by diwalaku      ########   odam.nl         */
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

/**
 * @brief Retrieves the exchange rate for a given date.
 *
 * Uses the exact date if available, otherwise uses the closest earlier date's rate.
 * Throws if no earlier date exists.
 */
double BitcoinExchange::getExchangeRateForDate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _exchangeRates.lower_bound(date);
	
	// case 1) exact match found
	if (it != _exchangeRates.end() && it->first == date)
		return it->second;
	// case 2) no exact match, but there are earlier dates available
	if (it == _exchangeRates.end())
	{
		--it;
		return it->second;
	}
	// case 3) no exact match and no earlier dates available
	if (it == _exchangeRates.begin())
	{
		throw std::runtime_error("No exchange rate available for date: " + date);
	}

	// case 4) no exact match, but there are earlier dates available
	--it;
	return it->second;
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
			std::cerr << "Error: Bad input -> " << line << std::endl;
			continue;
		}

		// 3. Extract date and value, trimming whitespace
		std::string date = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 1));
		if (date.empty() || valueStr.empty())
		{
			std::cerr << "Error: Bad input -> " << line << std::endl;
			continue;
		}

		// 4. Validate date
		if (!isValidDate(date))
		{
			std::cerr << "Error: Invalid date format in input -> " << date << std::endl;
			continue;
		}

		// 5. Validate value
		double value;
		try {
			value = std::stod(valueStr);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Invalid value in input: " << valueStr << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "Error: Not a positive number -> " << valueStr << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: Too large a number -> " << valueStr << std::endl;
			continue;
		}
			
		// 6. Look up exchange rate for the date (or closest previous date)
		double rate = 0;
		try {
			rate = getExchangeRateForDate(date);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			continue;
		}
		
		double result = value * rate;
		
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}