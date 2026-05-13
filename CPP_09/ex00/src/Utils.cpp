/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Utils.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 21:59:29 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/05/13 16:25:37 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

/**
 * @brief Trimes leading and trailing whitespace from a string.
 */
std::string BitcoinExchange::trim(const std::string& str) const
{
	size_t start = 0;
	
	while (start < str.length() && std::isspace(static_cast<unsigned char>(str[start])))
		++start;

	size_t end = str.length();
	while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
		end--;
	
	return str.substr(start, end - start);
}

/**
 * @brief Determines if a given year is a leap year.
 *
 * Leap year rules:
 * - A year is a leap year if divisible by 4
 * - EXCEPT if it's divisible by 100, it's not a leap year
 * - UNLESS it's divisible by 100 AND 400, it is a leap year
 * 
 * Examples:
 * - 2000 → leap year (divisible by 400)
 * - 1900 → not a leap year (divisible by 100, not 400)
 * - 2024 → leap year (divisible by 4, not 100)
 */
bool BitcoinExchange::isLeapYear(int year) const
{
	if (year % 400 == 0)
		return true;
	
	if (year % 100 == 0)
		return false;
	
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