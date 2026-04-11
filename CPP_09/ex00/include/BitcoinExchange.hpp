#pragma once

#include <iostream>

#define RESET   "\033[0m"
#define MAGENTA "\033[35m"
#define RED	 	"\033[31m"

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &assign);
		~BitcoinExchange();

		
};