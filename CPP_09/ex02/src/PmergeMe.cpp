/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/24 15:35:05 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/25 15:31:15 by diwalaku      ########   odam.nl         */
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

// Receives two individual pairs and compares them based on the first element of the pair.
// Checks if a is smaller than b
bool PmergeMe::comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return a.first < b.first;
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