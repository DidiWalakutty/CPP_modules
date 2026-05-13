/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/24 15:35:05 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/05/13 15:49:13 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv) 
{
	if (!validateInput(argv))
		throw std::invalid_argument("Error: Invalid input");
	parseInput(argv);
}

PmergeMe::PmergeMe(const PmergeMe &copy) : _vector(copy._vector), _deque(copy._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &assign)
{
	if (this != &assign)
	{
		_vector = assign._vector;
		_deque = assign._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

/**
 * @brief Validates the input arguments
 * 
 * Checks that:
 * - arguments are not empty
 * - arguments contain only digits
 * - arguments are non-negative integers
 * - there are no duplicates.
 *   unordered_set returns a pair (iterator, bool) where bool is false if the element already exists.
 */
bool PmergeMe::validateInput(char **argv)
{
	std::unordered_set<int> duplicates;
	
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
		
		if (!duplicates.insert(num).second)
			throw std::runtime_error("duplicate number found in input.");
	}

	return true;
}

/**
 * @brief Converts input arguments into integers and stores them
 * in both the vector and deque containers.
 */
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

/**
 * @brief Executes Ford-Johnson sort on both containers
 * and measures execution time in microseconds.
 * 
 * Time is measured separately for vector and deque to allow performance comparison.
 */
void PmergeMe::run()
{
	std::cout << "Before: ";
	printContainer(_vector);

	// --- Vector Sort ---
	auto startVec = std::chrono::high_resolution_clock::now();
	FJSortVector(_vector);
	auto endVec = std::chrono::high_resolution_clock::now();
	
	// --- Deque Sort ---
	auto startDeq = std::chrono::high_resolution_clock::now();
	FJSortDeque(_deque);
	auto endDeq = std::chrono::high_resolution_clock::now();
	
	std::cout << "After vec: ";
	printContainer(_vector);
	
	// --- Performance Output ---
	std::chrono::duration<double, std::micro> elapsedVec = endVec - startVec;
	std::chrono::duration<double, std::micro> elapsedDeq = endDeq - startDeq;
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << elapsedVec.count() << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  : " << elapsedDeq.count() << " us" << std::endl;
}