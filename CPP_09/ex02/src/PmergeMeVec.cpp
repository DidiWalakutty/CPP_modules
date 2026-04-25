/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMeVec.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/25 15:30:35 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/25 16:55:11 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

std::vector<size_t> generateJHVec(size_t limit)
{
	std::vector<size_t> jh;

	// base values
	jh.push_back(0); // J(0) = 0
	jh.push_back(1); // J(1) = 1

	// Keep generating jacobsthal until limit is reached
	while (true)
	{
		// element count
		size_t currentSize = jh.size();

		// last two values
		size_t last = jh[currentSize - 1];
		size_t secondLast = jh[currentSize - 2];

		// next jacobsthal number
		size_t next = last + 2 * secondLast;

		// Stop if next exceeds limit
		if (next >= limit)
			break;
		
		// Add next to the vector
		jh.push_back(next);
	}
	return jh;
}

/**
 * Sort pairs using the Ford-Johnson (merge-insert idea)
 * This function reorders PAIRS, not numbers.
 * 
 * Pair Format: (larger, smaller)
 * - We use the first element of the pair for comparisons.
 * - Each pair is treated as a single unit during sorting.
 * 
 * Goal: Sort pairs based only on their first value.
 * 
 * Example: [(5,3), (9,7), (8,4), (2,1)]
 * We compare:  
 *  - 5 vs 9 -> 9 is bigger, so (9,7) goes to big chain, (5,3) goes to small chain
 *  - 8 vs 2 -> 8 is bigger, so (8,4) goes to big chain, (2,1) goes to small chain
 */
void PmergeMe::sortVectorPairs(std::vector<std::pair<int, int> >& pairs)
{
	if (pairs.size() <= 1)
		return;
	
	std::vector<std::pair<int, int>> bigChain;
	std::vector<std::pair<int, int>> smallChain;

	// 1) Split into bigChain (bigger) and smallChain (smaller)
	for (size_t i = 0; i < pairs.size(); i += 2)
	{
		const std::pair<int, int>& current = pairs[i];
		const std::pair<int, int>& next = pairs[i + 1];

		if (current.first > next.first)
		{
			bigChain.push_back(current);
			smallChain.push_back(next);
		}
		else
		{
			bigChain.push_back(next);
			smallChain.push_back(current);
		}
	}

	// 2) If odd number of pairs, last pair is orphan and goes to pending chain.
	// example: [(5,3), (9,7), (8,4), (2,1), (6,0)] -> (6,0) is orphan, but still a pair
	if (pairs.size() % 2 != 0)
		smallChain.push_back(pairs.back());

	// 3) Recursively sort the bigChain of pairs:
	// Applies the same logic, but only to the bigger pairs, which reduces the num of comparisons.
	sortVectorPairs(bigChain);

	// 4) Insert pending pairs into sorted bigChain using binary search
	// lower_bound(start, end, value, comparison_rule)
	// - Uses comparePairs to find insertion position.
	// - returns iterator pointing to position of insertion.
	for (size_t i = 0; i < smallChain.size(); i++)
	{
		std::vector<std::pair<int, int>>::iterator it =
			std::lower_bound(bigChain.begin(), bigChain.end(), smallChain[i], comparePairs);
		bigChain.insert(it, smallChain[i]);
	}
	
	// Replace original
	pairs = bigChain;	
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
	
	// Vector of pairs to hold the paired elements: [3, 5, 9, 7] becomes -> [(5, 3), (9, 7)]
	std::vector<std::pair<int, int>> pairs;

	// Check if there's an odd element out (orphan)
	bool hasOrphan = (vec.size() % 2 != 0);
	int orphan = -1;
	
	// Store pair by creating pairs of two, ensuring the larger element is first in the pair.
	for (size_t i = 0; i < vec.size() - 1; i += 2)
	{
		int a = vec[i];
		int b = vec[i + 1];

		// swap will ensure the larger element is always first
		if (a < b)
			std::swap(a, b);

		pairs.push_back(std::make_pair(a, b));
	}

	// doesn't go in pairs, because it's one element and therefore "orphaned"
	// sort after sortVectorPairs
	if (hasOrphan)
		orphan = vec.back();

	sortVectorPairs(pairs);

	// Split sorted pairs into mainChain and pendChain:
	// mainchain = larger elements -> first element of each pair
	// pendchain = smaller elements -> second element of each pair
	std::vector<int> mainChain;
	std::vector<int> pendChain;
	
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pendChain.push_back(pairs[i].second);
	}

	// apply jacobsthal ordering = which order to insert pendChain elements into mainChain
	
	std::vector<size_t> jacobsthal = generateJHVec(pendChain.size());
	
	// insert using lower_bound

	// insert orphan at the end if exists
	if (hasOrphan)
	{
		auto it = std::lower_bound(mainChain.begin(), mainChain.end(), orphan);
		mainChain.insert(it, orphan);
	}
}