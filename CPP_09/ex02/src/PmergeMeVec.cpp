/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMeVec.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/25 15:30:35 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/05/07 20:59:58 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

/**
 * @brief Builds the insertion order for pendChain using Jacobsthal grouping.
 *
 * Jacobsthal numbers follow: J(n) = J(n-1) + 2 * J(n-2)
 * Sequence: 0, 1, 1, 3, 5, 11, 21, 43, ... => starts at index 0
 *
 * These numbers are used as boundaries to split pendChain into index ranges ("chunks").
 * By inserting in a non-linear order, we reduce the number of comparisons needed.
 *
 * Each chunk is converted into indices and flattened in reverse order,
 * which improves binary search insertion efficiency.
 *
 * Example (n = 5):
 * Jacobsthal: 0, 1, 1, 3
 * Chunks:
 *   [0–1] → indices [0]
 *   [1–3] → indices [2, 1]
 *   [3–5] → indices [4, 3]
 * Final order: [0, 2, 1, 4, 3] => which is 'order' in FJSortVector.
 * 
 * Leftover elements that don't fit into a full chunk are added at the end.
 */
std::vector<size_t> PmergeMe::buildJacobsthalOrderVec(size_t n)
{
	std::vector<size_t> jh;		// Jacobsthal numbers
	std::vector<size_t> order;	// final insertion order
	
	if (n == 0)
		return order;
		
	// 1) Generate Jacobsthal sequence + add base cases to start the sequence.
	jh.push_back(0);
	jh.push_back(1);

	// build sequence up to size limit n
	while (true)
	{
		size_t size = jh.size();

		// J(2) = 1 + 2*0 = 1
		// J(3) = 1 + 2*1 = 3
		size_t next = jh[size - 1] + 2 * jh[size - 2]; 

		// Stop if next Jacobsthal number exceeds n (can not form a valid chunk)
		if (next >= n)
			break;
	
		jh.push_back(next);
	}

	// 2) Convert Jacobsthal boundaries into index chunks
	//    Skip first 2 values since they don't form valid chunks
	size_t start = 0;
	for (size_t i = 2; i < jh.size(); ++i)
	{
		// Takes the smaller value to avoid going out of bounds
		size_t end = std::min(jh[i], n);

		// 3) Add indices in reverse order inside the chunk
		for (size_t j = end; j > start; --j)
			order.push_back(j - 1);

		start = end;
	}

	// 4) Add remaining indices that don't fit into a full chunk
	for (size_t i = n; i > start; --i)
		order.push_back(i - 1);

	return order;
}

/**
 * @brief Merges two sorted halves of vector pairs into one sorted vector.
 *
 * Both halves are already sorted by '.first' because they were recursively processed
 * by sortVecByFirst(), which uses this same merge step.
 *
 * The merge process compares the '.first' values of both halves and builds a new
 * globally sorted sequence. At each step, the smaller element is selected and its
 * iterator is advanced. Once one half is fully consumed, the remaining elements of
 * the other half are appended (since they are already sorted).
 *
 * Example:
 * left  = [(20, 1), (50, 8)]
 * right = [(40, 3), (66, 2)]
 *
 * result = [(20, 1), (40, 3), (50, 8), (66, 2)]
 */
static void mergeVec(std::vector<std::pair<int, int>> &result,
			   const std::vector<std::pair<int, int>> &left,
			   const std::vector<std::pair<int, int>> &right)
{
	size_t l = 0;
	size_t r = 0;
	size_t i = 0;
	
	while (l < left.size() && r < right.size())
	{
		if (left[l].first <= right[r].first)
			result[i++] = left[l++];
		else
			result[i++] = right[r++];
	}

	while (l < left.size())
		result[i++] = left[l++];
	while (r < right.size())
		result[i++] = right[r++];
}

/**
 * @brief Recursively sorts vector pairs by their '.first' value using merge sort.
 * 
 * This function:
 * 1) Splits the array into two halves
 * 2) Recursively sorts each half
 * 3) Merges the sorted halves using merge()
 * 
 * The recurrsion keeps breaking down the vector, until it reaches single-element pairs. 
 * At that point, merge() is called to sort + create a sorted half.
 * 
 * Example:
 * [(50, 8), (20, 1), (66, 2), (40, 3)]
 * Splits into:
 *  - Left:  [(50, 8), (20, 1)]
 *  - Right: [(66, 2), (40, 3)]
 * Then keeps splitting until: [(20, 1)], [(50, 8)], [(40, 3)], [(66, 2)]
 */
void PmergeMe::sortVecByFirst(std::vector<std::pair<int, int>>& pairs)
{
	if (pairs.size() <= 1)
		return;
	
	size_t mid = pairs.size() / 2;
	
	std::vector<std::pair<int, int>> left(pairs.begin(), pairs.begin() + mid);
	std::vector<std::pair<int, int>> right(pairs.begin() + mid, pairs.end());
	
	sortVecByFirst(left);
	sortVecByFirst(right);
	mergeVec(pairs, left, right);
}

/**
 * @brief Sorts a vector using the Ford-Johnson (merge-insert) algorithm.
 * 
 * Steps:
 * 1) Pair elements into ordered pairs (larger, smaller)
 * 2) Create the hierarchy by resursively sorting pairs by their larger element (the first of the pair)
 * 3) Split pairs into:
 *    - mainChain (sorted winners, now sorted)
 *    - pendChain (unsorted losers)
 * 4) Build Jacobsthal order for pendChain insertion
 * 5) Merge pendChain into mainChain using Jacobsthal order for efficient insertions.
 * 6) Handle orphan element if available
 */
void PmergeMe::FJSortVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;
	
	std::vector<std::pair<int, int>> pairs;

	bool hasOrphan = (vec.size() % 2 != 0);
	int orphan = -1;
	
	// 1) Pair in elements of 2 and order them (larger, smaller)
	for (size_t i = 0; i < vec.size() - 1; i += 2)
	{
		int a = vec[i];
		int b = vec[i + 1];
		
		if (a < b)
			std::swap(a, b);

		pairs.push_back(std::make_pair(a, b));
	}

	if (hasOrphan)
		orphan = vec.back();

	// 2) Build hierachy by sorting pairs
	sortVecByFirst(pairs);
	
	// 3) Split pairs into mainChain and pendChain by flattening the sorted pairs
	std::vector<int> mainChain;
	std::vector<int> pendChain;
	
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pendChain.push_back(pairs[i].second);
	}

	// 4) Build Jacobsthal order for pendChain insertion
	std::vector<size_t> order = buildJacobsthalOrderVec(pendChain.size());	

	// 5) Insert pendChain elements into mainChain in Jacobsthal order via binary search.
	//    order[] contains positions in pendChain (not the values themselves).
	for (size_t i = 0; i < order.size(); i++)
	{
		int value = pendChain[order[i]];

		std::vector<int>::iterator it =
			std::lower_bound(mainChain.begin(), mainChain.end(), value);

		mainChain.insert(it, value);
	}

	// 6) Insert orphan if it exists
	if (hasOrphan)
	{
		auto it = std::lower_bound(mainChain.begin(), mainChain.end(), orphan);
		mainChain.insert(it, orphan);
	}

	vec = mainChain;
}
