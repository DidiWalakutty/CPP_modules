/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/24 15:35:05 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/24 21:13:21 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv) 
{
	if (!validateInput(argv))
		throw std::invalid_argument("Error: Invalid input");
	parseInput(argv);
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::validateInput(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		std::string str = argv[i];

		if (str.empty())
			return false;
		for (size_t j = 0; j < str.size(); j++)
		{
			if (!std::isdigit(str[j]))
				throw std::runtime_error("invalid character in input.");
		}

		int num = std::atoi(str.c_str());
		if (num < 0)
			throw std::runtime_error("negative number found in input.");
	}

	return true;
}

void PmergeMe::parseInput(char **argv)
{
	for (int i = 1; argv[i] != nullptr; i++)
	{
		int num = std::atoi(argv[i]);
		if (num < 0)
			throw std::invalid_argument("Error: Negative numbers are not allowed");
		_vector.push_back(num);
		_deque.push_back(num);
	}
}

// example pairs: [(5,3), (9,7), (8,4), (2,1)]
// no jacobsthal needed, because the pairs are already sorted by their first element
// structural sorting of the mainChain only
void PmergeMe::sortVectorPairs(std::vector<std::pair<int, int> >& pairs)
{
	if (pairs.size() <= 1)
		return;
	
	std::vector<std::pair<int, int>> mainChain;
	std::vector<std::pair<int, int>> pendChain;

	// Distribute the pairs into main and pending chains
	for (size_t i = 0; i < pairs.size(); i += 2)
	{
		const std::pair<int, int>& current = pairs[i];
		const std::pair<int, int>& next = pairs[i + 1];

		// Compare the first elements of the pairs:
		// (5, 3) vs (9, 7)
		// (8, 4) vs (2, 1)
		if (current.first > next.first)
		{
			mainChain.push_back(current);
			pendChain.push_back(next);
		}
		else
		{
			pendChain.push_back(current);
			mainChain.push_back(next);
		}
	}

	// Handle the case of an odd number of pairs (orphan)
	if (pairs.size() % 2 != 0)
		mainChain.push_back(pairs.back());

	// Recursively sort the main chain
	sortVectorPairs(mainChain);

	// Insert the pending chain elements into the sorted main chain
	for (size_t i = 0; i < pendChain.size(); i++)
	{
		std::vector<std::pair<int, int> >::iterator it =
			std::lower_bound(mainChain.begin(), mainChain.end(), pendChain[i],
				[](const std::pair<int, int>& a, const std::pair<int, int>& b) 
				{
					return a.first < b.first;
				}
			);
		mainChain.insert(it, pendChain[i]);
	}

	// Replace original
	pairs = mainChain;	
}

/**
 * @brief Main Ford-Johnson function
 * 
 * @param vec 
 */
void PmergeMe::FJSortVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;
	
	// Vector of pairs to hold the paired elements
	// [3, 5, 9, 7] becomes -> [(5, 3), (9, 7)]
	std::vector<std::pair<int, int>> pairs;

	// Check if there's an odd element out (orphan)
	bool hasOrphan = (vec.size() % 2 != 0);
	int orphan = -1;
	
	//
	for (size_t i = 0; i < vec.size() - 1; i += 2)
	{
		int a = vec[i];
		int b = vec[i + 1];

		// swap will ensure the larger element is always first in the pair
		if (a < b)
			std::swap(a, b);

		pairs.push_back(std::make_pair(a, b));
	}

	// doesn't go in pairs, because it's one element and therefore "orphaned"
	if (hasOrphan)
		orphan = vec.back();

	sortVectorPairs(pairs);
}

void PmergeMe::run()
{
	std::cout << "Before: ";
	printContainer(_vector);

	auto startVec = std::chrono::high_resolution_clock::now();
	FJSortVector(_vector);
	auto endVec = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsedVec = endVec - startVec;

	auto startDeq = std::chrono::high_resolution_clock::now();
	FJSortDeque(_deque);
	auto endDeq = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsedDeq = endDeq - startDeq;

	std::cout << "After: ";
	printContainer(_vector);

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << elapsedVec.count() << " seconds" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  : " << elapsedDeq.count() << " seconds" << std::endl;
}