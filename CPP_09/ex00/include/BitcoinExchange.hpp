#pragma once

#include <iostream>
#include <fstream>
#include <map>

#define RESET   "\033[0m"
#define MAGENTA "\033[35m"
#define RED	 	"\033[31m"

class BitcoinExchange
{
	private:
		std::map<std::string, double> _exchangeRates;	// date -> rate, automatically sorted by key (YYYY-MM-DD)
		
		void loadCSV(const std::string& dataFile);
		bool isValidDate(const std::string& date) const;
		double getExchangeRateForDate(const std::string& date) const;
		
		// helper functions
		std::string trim(const std::string& str) const;
		bool isLeapYear(int year) const;
		int getDaysInMonth(int month, int year) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &dataFile);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &assign);
		~BitcoinExchange();

		void processInputFile(const std::string &inputFile);

		
};