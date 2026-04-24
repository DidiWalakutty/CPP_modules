/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 20:05:39 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/22 22:48:28 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv)
{
	if (!validateInput(argv))
		throw std::invalid_argument("Error: ");
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
	for (int i = 1; argv[i]; i++)
	{
		int num = std::atoi(argv[i]);
		_vector.push_back(num);
		_deque.push_back(num);
	}
}

/**
 * @brief Execute the Ford-Johnson algorithm and measures the time taken.
 * 
 * - Prints the original unsorted vector.
 * - Sorts the vector using FJSortVector.
 * - Sorts the deque using FJSortDeque.
 * - Measures execution time in microseconds for both vector and deque.
 * - Uses steady_clock for more accurate timing (not affected by system clock changes).
 */
void PmergeMe::run()
{
	std::cout << "Before: ";
	printContainer(_vector);

	// --- Vector ---
	auto startVec = std::chrono::steady_clock::now();
	FJSortVector(_vector);
	auto endVec = std::chrono::steady_clock::now();
	auto durationVec = std::chrono::duration_cast<std::chrono::microseconds>(endVec - startVec).count();
	
	// --- Deque ---
	auto startDeq = std::chrono::steady_clock::now();
	FJSortDeque(_deque);
	auto endDeq = std::chrono::steady_clock::now();
	auto durationDeq = std::chrono::duration_cast<std::chrono::microseconds>(endDeq - startDeq).count();

	// print sorted vector and timing results
	std::cout << "After:  "; 
	printContainer(_vector);

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << durationVec << " microseconds" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << durationDeq << " microseconds" << std::endl;
}

/**
 * @brief Inserts all elements from pendChain into the already sorted mainChain.
 *
 * Uses std::lower_bound (binary search) to find the correct insertion position
 * for each element, ensuring mainChain remains sorted after each insertion.
 */
void PmergeMe::insertSmallVecChain(std::vector<int> &mainChain, const std::vector<int> &pendChain)
{
	for (size_t i = 0; i < pendChain.size(); i++)
	{
		int small = pendChain[i];
		auto it = std::lower_bound(mainChain.begin(), mainChain.end(), small);

		mainChain.insert(it, small);
	}
}

/**
 * @brief Ford–Johnson merge-insert sorting algorithm (vector version).
 *
 * Steps:
 * - Split input into pairs of elements to compare + separate into larger and smaller elements.
 * - Assign larger elements to mainChain, smaller to pendChain
 * - If input size is odd, the last element (orphan) is unpaired and added to mainChain
 * - Recursively sort mainChain (divide-and-conquer step)
 * - Insert pendChain elements into sorted mainChain using binary search
 * - Replace original vector with fully sorted result
 */
void PmergeMe::FJSortVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;

	// organize into pairs
	std::vector<int> mainChain;
	std::vector<int> pendChain;

	bool orphan = (vec.size() % 2 != 0);
	
	// loop in steps of 2 to create pairs.
	for (size_t i = 0; i < vec.size() - 1; i += 2)
	{
		if (vec[i] > vec[i + 1])
		{
			mainChain.push_back(vec[i]);
			pendChain.push_back(vec[i + 1]);
		}
		else
		{
			mainChain.push_back(vec[i + 1]);
			pendChain.push_back(vec[i]);
		}
	}

	// pushes last element (vec.back()) to mainChain if number of elements is odd (orphan)
	if (orphan)
		mainChain.push_back(vec.back());
	
	// recursively sort big chain
	FJSortVector(mainChain);

	// then insert small chain
	insertSmallVecChain(mainChain, pendChain);

	vec = mainChain;
}

void PmergeMe::insertSmallDeqChain(std::deque<int> &mainChain, const std::deque<int> &pendChain)
{
	for (size_t i = 0; i < pendChain.size(); i++)
	{
		int small = pendChain[i];
		auto it = std::lower_bound(mainChain.begin(), mainChain.end(), small);

		mainChain.insert(it, small);
	}

}

void PmergeMe::FJSortDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;

	std::deque<int> mainChain;
	std::deque<int> pendChain;

	bool orphan = (deq.size() % 2 != 0);

	// static_cast to int to avoid warnings about signed/unsigned comparison
	for (int i = 0; i < static_cast<int>(deq.size()) - 1; i += 2)
	{
		if (deq[i] > deq[i + 1])
		{
			mainChain.push_back(deq[i]);
			pendChain.push_back(deq[i + 1]);
		}
		else
		{
			mainChain.push_back(deq[i + 1]);
			pendChain.push_back(deq[i]);
		}
	}
	if (orphan)
		mainChain.push_back(deq.back());

	// recursively sort big chain
	FJSortDeque(mainChain);

	// then insert small chain
	insertSmallDeqChain(mainChain, pendChain);

	deq = mainChain;
}