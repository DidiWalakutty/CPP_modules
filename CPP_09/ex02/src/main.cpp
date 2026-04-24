/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 20:05:36 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/24 19:54:46 by diwalaku      ########   odam.nl         */
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
		
		/// !!! duplicates: The management of errors related to duplicates is left to your discretion.

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

/**
 * @brief Ford Johnson (merge insert) sort has 3 phases
 * 
 * 1. Pairing
 *    Group elements into pairs and normalize them: (a, b) -> (min(a, b), max(a, b))
 * 2. Recursive Sorting
 *    Sort the pairs by their larger elements.
 * 3. Controlled Insertion
 *    Insert the smaller elements into the sorted chain, through Jacobsthal sequence, to minimize comparisons. 
 * 
 */