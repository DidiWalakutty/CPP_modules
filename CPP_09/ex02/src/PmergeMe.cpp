/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 20:05:39 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/18 02:05:00 by diwalaku      ########   odam.nl         */
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

void PmergeMe::run()
{
	// std::cout << "Before: ";
	// printContainer(_vector);

	// add timers
	FJSortVector(_vector);
	// FJSortDeque(_deque);

	// std::cout << "After:  " << std::endl; 
	// printContainer(_vector);

	// std::cout << "Time taken to sort vector with << " << _vector.size() << " elements: " << std::endl;
	// std::cout << "Time taken to sort deque with << " << _deque.size() << " elements: " << std::endl;

}

/**
 * Merge Insert: pendChain (smallest) into mainChain (largest + sorted):
 * 
 */



// void PmergeMe::FJMergeInsertVector(std::vector<int> &mainChain, const std::vector<int> &pendChain)
// {
	
// }

// void FJMergeInsertDeque(std::deque<int> &mainChain, const std::deque<int > &pendChain)
// {

// }

/**
 * Ford-Johnson sorting:
 * - Pair elements into big/small chains
 * - Handle orphan element if size is odd
 * - Recursively sort mainChain (breaks problem into smaller subproblems
 *   until size <= 1)
 * - Insert pendChain into sorted mainChain
 * - Replace original vector with final sorted result
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

	if (orphan)
		mainChain.push_back(vec.back());

	// std::cout << "Big chain: ";
	// printContainer(mainChain);
	// std::cout << "Small chain: ";
	// printContainer(pendChain);
	
	// recursively sort big chain
	FJSortVector(mainChain);

	// then insert small chain
	// FJMergeInsertVector(mainChain, pendChain);

	// vec = mainChain;
}


// void PmergeMe::FJSortDeque(std::deque<int> &deq)
// {
// 	if (deq.size() <= 1)
// 		return;

// 	std::deque<int> mainChain;
// 	std::deque<int> pendChain;

// 	bool orphan = (deq.size() % 2 != 0);

// 	// static_cast to int to avoid warnings about signed/unsigned comparison
// 	for (int i = 0; i < static_cast<int>(deq.size()) - 1; i += 2)
// 	{
// 		if (deq[i] > deq[i + 1])
// 		{
// 			mainChain.push_back(deq[i]);
// 			pendChain.push_back(deq[i + 1]);
// 		}
// 		else
// 		{
// 			mainChain.push_back(deq[i + 1]);
// 			pendChain.push_back(deq[i]);
// 		}
// 	}
// 	if (orphan)
// 		mainChain.push_back(deq.back());
	
// 	// std::cout << "Big chain: ";
// 	// printContainer(mainChain);
// 	// std::cout << "Small chain: ";
// 	// printContainer(pendChain);

// 	// now sort big chain
// 	FJSortDeque(mainChain);

// 	// then insert small chain
// 	FJMergeInsertDeque(mainChain, pendChain);
// }