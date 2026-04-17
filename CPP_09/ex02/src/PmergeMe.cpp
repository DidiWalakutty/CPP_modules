/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 20:05:39 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/18 00:37:25 by diwalaku      ########   odam.nl         */
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
				throw std::runtime_error("Error: invalid character in input.");
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
	FJSortDeque(_deque);

	// std::cout << "After:  " << std::endl; 
	// printContainer(_vector);

	// std::cout << "Time taken to sort vector with << " << _vector.size() << " elements: " << std::endl;
	// std::cout << "Time taken to sort deque with << " << _deque.size() << " elements: " << std::endl;

}

// do binary search through lower_bound to find correct position for small chain element
// Each elelemnt is individually inserted into the correct position, so no need to sort.
void PmergeMe::FJMergeInsert(std::vector<int> &Bigchain, const std::vector<int> &smallChain)
{
	for (size_t i = 0; i < smallChain.size(); i++)
	{
		// use lower_bound (std library function) to find the correct position to insert smallChain[i]
		
	}
}

/**
 * Ford-Johnson sorting:
 * - Pair elements into big/small chains
 * - Handle orphan element if size is odd
 * - Recursively sort bigChain (breaks problem into smaller subproblems
 *   until size <= 1)
 * - Insert smallChain into sorted bigChain
 * - Replace original vector with final sorted result
 */
void PmergeMe::FJSortVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;

	// organize into pairs
	std::vector<int> bigChain;
	std::vector<int> smallChain;

	bool orphan = (vec.size() % 2 != 0);
	
	// loop in steps of 2 to create pairs.
	for (size_t i = 0; i < vec.size() - 1; i += 2)
	{
		if (vec[i] > vec[i + 1])
		{
			bigChain.push_back(vec[i]);
			smallChain.push_back(vec[i + 1]);
		}
		else
		{
			bigChain.push_back(vec[i + 1]);
			smallChain.push_back(vec[i]);
		}
	}

	if (orphan)
		bigChain.push_back(vec.back());

	// std::cout << "Big chain: ";
	// printContainer(bigChain);
	// std::cout << "Small chain: ";
	// printContainer(smallChain);
	
	// recursively sort big chain
	FJSortVector(bigChain);

	// then insert small chain
	FJMergeInsert(bigChain, smallChain);

	vec = bigChain;
}





void PmergeMe::FJSortDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;

	std::deque<int> bigChain;
	std::deque<int> smallChain;

	bool orphan = (deq.size() %2 != 0);

	// static_cast to int to avoid warnings about signed/unsigned comparison
	for (int i = 0; i < static_cast<int>(deq.size()) - 1; i += 2)
	{
		if (deq[i] > deq[i + 1])
		{
			bigChain.push_back(deq[i]);
			smallChain.push_back(deq[i + 1]);
		}
		else
		{
			bigChain.push_back(deq[i + 1]);
			smallChain.push_back(deq[i]);
		}
	}
	if (orphan)
		bigChain.push_back(deq.back());
	
	// std::cout << "Big chain: ";
	// printContainer(bigChain);
	// std::cout << "Small chain: ";
	// printContainer(smallChain);

	// now sort big chain
	// then insert small chain
}