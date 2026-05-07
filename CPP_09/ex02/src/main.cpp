/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 20:05:36 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/05/07 16:59:54 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"


int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe <numbers...>" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe FJSorter(argv);
		FJSorter.run();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	}
	
	return 0;
}
