/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMeDeq.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/25 19:27:36 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/05/07 20:50:40 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

std::deque<size_t> PmergeMe::buildJacobsthalOrderDeq(size_t n)
{
	std::deque<size_t> jh;
	std::deque<size_t> order;

	if (n == 0)
		return order;
		
	jh.push_back(0);
	jh.push_back(1);

	while (true)
	{
		size_t size = jh.size();
		
		// J(n) = J(n-1) + 2*J(n-2)
		size_t next = jh[size - 1] + 2 * jh[size - 2];

		if (next >= n)
			break;

		jh.push_back(next);
	}

	size_t start = 0;
	for (size_t i = 2; i < jh.size(); ++i)
	{
		size_t end = std::min(jh[i], n);

		for (size_t j = end; j > start; --j)
			order.push_back(j - 1);

		start = end;
	}

	for (size_t i = n; i > start; --i)
		order.push_back(i - 1);

	return order;
}

static void mergeDeq(std::deque<std::pair<int, int>> &result,
			   const std::deque<std::pair<int, int>> &left,
			   const std::deque<std::pair<int, int>> &right)
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

void PmergeMe::sortDeqByFirst(std::deque<std::pair<int, int>>& pairs)
{
	if (pairs.size() <= 1)
		return;
	
	size_t mid = pairs.size() / 2;
	
	std::deque<std::pair<int, int>> left(pairs.begin(), pairs.begin() + mid);
	std::deque<std::pair<int, int>> right(pairs.begin() + mid, pairs.end());
	
	sortDeqByFirst(left);
	sortDeqByFirst(right);
	mergeDeq(pairs, left, right);
}

void PmergeMe::FJSortDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;

	std::deque<std::pair<int, int>> pairs;

	bool hasOrphan = (deq.size() % 2 != 0);
	int orphan = -1;

	for (size_t i = 0; i < deq.size() - 1; i += 2)
	{
		int a = deq[i];
		int b = deq[i + 1];
		
		if (a < b)
			std::swap(a, b);

		pairs.push_back(std::make_pair(a, b));
	}

	if (hasOrphan)
		orphan = deq.back();

	sortDeqByFirst(pairs);

	std::deque<int> mainChain;
	std::deque<int> pendChain;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pendChain.push_back(pairs[i].second);
	}

	std::deque<size_t> order = buildJacobsthalOrderDeq(pendChain.size());
	
	for (size_t i = 0; i < order.size(); i++)
	{
		int value = pendChain[order[i]];

		std::deque<int>::iterator it =
			std::lower_bound(mainChain.begin(), mainChain.end(), value);

		mainChain.insert(it, value);
	}

	if (hasOrphan)
	{
		auto it = std::lower_bound(mainChain.begin(), mainChain.end(), orphan);
		mainChain.insert(it, orphan);
	}
	
	deq = mainChain;
}