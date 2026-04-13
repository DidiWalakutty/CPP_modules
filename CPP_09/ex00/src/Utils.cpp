/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Utils.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 21:59:29 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/14 00:53:53 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

std::string BitcoinExchange::trim(const std::string& str) const
{
	size_t start = 0;
	// Trim leading whitespace
	while (start < str.length() && std::isspace(static_cast<unsigned char>(str[start])))
		++start;

	size_t end = str.length();
	// Trim trailing whitespace
	while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
		end--;
	
	// Return the trimmed string
	return str.substr(start, end - start);
}

/**
 * @brief Determines if a given year is a leap year.
 *
 * Applies standard leap year rules (divisible by 4, except centuries
 * unless divisible by 400).
 */
bool BitcoinExchange::isLeapYear(int year) const
{
	// divisible by 400 -> Leap Year
	if (year % 400 == 0)
		return true;
	
	// divisible by 100 but not by 400 -> Not a Leap Year
	if (year % 100 == 0)
		return false;
	
	// Otherwise: divisible by 4 -> Leap Year
	return (year % 4 == 0);
}

/**
 * @brief Validates a date string in "YYYY-MM-DD" format.
 *
 * Checks format, numeric values, and ensures the day is valid
 * for the given month and year.
 */
int BitcoinExchange::getDaysInMonth(int month, int year) const
{
	if (month == 2)
	{
		if (isLeapYear(year))
			return 29;
		else
			return 28;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	return 31;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	
	// Check that all other characters are digits
	for (size_t i = 0; i < date.length(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int year = 0;
	int month = 0;
	int day = 0;

	try {
		year = std::stoi(date.substr(0, 4));
		month = std::stoi(date.substr(5, 2));
		day = std::stoi(date.substr(8, 2));
	}
	catch (const std::exception &e)
	{
		return false;
	}

	if (month < 1 || month > 12)
		return false;
	
	int daysInThisMonth = getDaysInMonth(month, year);
	if (day < 1 || day > daysInThisMonth)
		return false;

	return true;
}