/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 18:07:59 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/14 17:24:38 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
{
		std::cerr << RED << "Error: Correct Usage: ./btc <input_file>" << RESET << std::endl;
		return 1;
	}
	
	try
	{
		BitcoinExchange btcExchange("data/data.csv");
		btcExchange.processInputFile(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}