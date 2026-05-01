/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMeVec.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/25 15:30:35 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/05/01 19:26:13 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

/**
 * Builds insertion order for pendChain using Jacobsthal grouping.
 *
 * 📌 Function:
 * - Generates Jacobsthal sequence that define the chunk boundaries
 * - With these numners we create index ranges (chunks)
 * - Each chunk represents a range of pendChain elements
 * - Each chunk is processed in reverse order
 * - This non-linear order spreads insertions efficiently and avoids duplicates.
 * - Leftover elements are handled at the end
 *
 * 📌 Why reverse?
 * - Higher indices depend on larger insertion ranges
 * - Inserting them first reduces binary search comparisons
 */
std::vector<size_t> PmergeMe::buildJacobsthalOrder(size_t n)
{
	std::vector<size_t> jh;		// Jacobsthal numbers
	std::vector<size_t> order;	// final insertion order
	
	if (n == 0)
		return order;
		
	// 1) Generate Jacobsthal sequence
	jh.push_back(0); // J(0) = 0
	jh.push_back(1); // J(1) = 1

	// build JH sequence up to size limit n
	while (true)
	{
		// element count
		size_t size = jh.size();

		// J(2) = 1 + 2*0  = 1 + 2 * 0 = 1
		// J(3) = 1 + 2*1  = 1 + 2 * 1 = 3
		// J(n) = J(n-1) + 2*J(n-2)
		size_t next = jh[size - 1] + 2 * jh[size - 2]; 

		// Stop if next Jacobsthal number exceeds n, since we only need indices up to n
		if (next >= n)
			break;
	
		jh.push_back(next);
	}

	// 2) Convert Jacobsthal into chunks
	// Uses the differences between JH values and uses them as boundaries.
	// example: JH = [0, 1, 3]
	// Chunks: [0-1], [1-3]
	// chunks: 3 - 1 = size 2 | 5 - 3 = size 2 | 11 - 5 = size 6 
	// Turn ranges into actual indices: [0] and [2, 1] (reversed)
	// combined: [0, 2, 1]
	size_t start = 0;

	// skip first 2 values (0, 1 aren't useful for chunking)
	for (size_t i = 2; i < jh.size(); ++i)
	{
		// Takes the smaller value to avoid going out of bounds
		size_t end = std::min(jh[i], n);

		// 3) Reverse each chunk
		// this converts the range into actual insertion indices in reverse order.
		// example: chunk [1-3] becomes indices [2, 1] instead of [1, 2]
		for (size_t j = end; j > start; --j)
			order.push_back(j - 1);

		start = end;
	}

	// 4) Handle leftovers that didn't fit into a full chunk
	for (size_t i = n; i > start; --i)
		order.push_back(i - 1);

	return order;
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
void PmergeMe::sortVectorPairs(std::vector<std::pair<int, int>>& pairs)
{
	if (pairs.size() <= 1)
		return;
	
	std::vector<std::pair<int, int>> bigChain;
	std::vector<std::pair<int, int>> smallChain;

	// 1) Compare + split pairs two-by-two 
	//    i + 1 always ensures there's a second element to compare with 
	for (size_t i = 0; i + 1 < pairs.size(); i += 2)
	{
		std::pair<int, int>& a = pairs[i];
		std::pair<int, int>& b = pairs[i + 1];

		// Compare ONLY on .first (winner of the pair)
		if (a.first < b.first)
			std::swap(a, b);
		
		bigChain.push_back(a); // bigger goes to bigChain
		smallChain.push_back(b); // smaller goes to smallChain
	}

	// 2) If odd number of pairs, last pair is orphan and goes to pending chain.
	if (pairs.size() % 2 != 0)
		smallChain.push_back(pairs.back());

	// 3) Recursively sort the bigChain of pairs:
	// Applies the same logic, but only to the bigger pairs, which reduces the num of comparisons.
	sortVectorPairs(bigChain);

	// 4) Rebuild structure
	pairs.clear();

	// Add sorted bigChain first, then smallChain to maintain the hierarchy of winners and losers. 
	for (size_t i = 0; i < bigChain.size(); i++)
		pairs.push_back(bigChain[i]);

	for (size_t i = 0; i < smallChain.size(); i++)
		pairs.push_back(smallChain[i]);
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
	
	// 1) Build Pairs
	std::vector<std::pair<int, int>> pairs;

	bool hasOrphan = (vec.size() % 2 != 0);
	int orphan = -1;
	
	// Create pairs of elements and sort them internally
	for (size_t i = 0; i < vec.size() - 1; i += 2)
	{
		int a = vec[i];
		int b = vec[i + 1];
		// swap will ensure the larger element is always first
		if (a < b)
			std::swap(a, b);

		pairs.push_back(std::make_pair(a, b));
	}

	if (hasOrphan)
		orphan = vec.back();

	// std::cout << "Initial pairs (larger, smaller): ";
	// for (size_t i = 0; i < pairs.size(); i++)
	// 	std::cout << "(" << pairs[i].first << "," << pairs[i].second << ") ";
	// std::cout << "\n";	

	// 2) Build hierachy by sorting pairs
	sortVectorPairs(pairs);
	
	// 3) Extract chains into mainChain and pendChain by flattening the sorted pairs:
	std::vector<int> mainChain;
	std::vector<int> pendChain;
	
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pendChain.push_back(pairs[i].second);
	}
	// std::cout << "Main/Pend after flattening:\n";
	// std::cout << "mainChain (sorted pairs): ";
	// printContainer(mainChain);
	// std::cout << "pendchain (unsorted pairs): ";
	// printContainer(pendChain);

	// 4) Sort mainChain
	std::vector<int> sortedMain;

	for (size_t i = 0; i < mainChain.size(); i++)
	{
		std::vector<int>::iterator it =
			std::lower_bound(sortedMain.begin(), sortedMain.end(), mainChain[i]);

		sortedMain.insert(it, mainChain[i]);
	}
	mainChain = sortedMain;
	
	// 5) Build Jacobsthal order for pendChain insertion
	std::vector<size_t> order = buildJacobsthalOrder(pendChain.size());
	
	// std::cout << "Jacobsthal insertion order for pendChain: ";
	// for (size_t i = 0; i < order.size(); i++)
	// 	std::cout << order[i] << " ";
	// std::cout << "\n";
	
	
	// 6) Insert pendChain into mainChain based on Jacobsthal order
	for (size_t i = 0; i < order.size(); i++)
	{
		int value = pendChain[order[i]];

		// Find insertion point in mainChain using binary search
		std::vector<int>::iterator it =
			std::lower_bound(mainChain.begin(), mainChain.end(), value);

		mainChain.insert(it, value);
	}

	
	// 7) Insert orphan if it exists
	if (hasOrphan)
	{
		auto it = std::lower_bound(mainChain.begin(), mainChain.end(), orphan);
		mainChain.insert(it, orphan);
	}

	vec = mainChain;
}
