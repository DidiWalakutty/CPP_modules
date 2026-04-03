/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 15:03:17 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/03 16:48:06 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <iostream>

int main()
{
	std::cout << MAGENTA << "1) --- Subject Test ---" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << MAGENTA << "\n2) --- Too few elements ---" << RESET << std::endl;
	Span sp2 = Span(3);
	try {
		sp2.addNumber(5);
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA << "\n3) --- Too many numbers added ---" << RESET << std::endl;
	Span sp3 = Span(2);
	try {
		sp3.addNumber(100);
		sp3.addNumber(800);
		sp3.addNumber(46);
		std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA << "\n4) --- Negatives ---" << RESET << std::endl;
	Span sp4 = Span(4);
	try {
		sp4.addNumber(-300);
		sp4.addNumber(800);
		sp4.addNumber(-50);
		std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp4.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA << "\n5) --- Duplicates ---" << RESET << std::endl;
	Span sp5 = Span(4);
	try {
		sp5.addNumber(5);
		sp5.addNumber(5);
		sp5.addNumber(20);
		sp5.addNumber(10);
		std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << MAGENTA << "\n6) --- 10.000 numbers: ---" << RESET << std::endl;
	
	std::vector<int> largeVector;
	// Add numbers from 0 to 9999 to the vector
	for (int i = 0; i < 10000; i++)
		largeVector.push_back(i);
	
	Span bigSpan = Span(1000);
	try {
		bigSpan.addMultipleNumbers(largeVector.begin(), largeVector.end());
		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}