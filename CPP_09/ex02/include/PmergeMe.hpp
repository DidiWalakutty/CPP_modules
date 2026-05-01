#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <algorithm>

template <typename T>
void printContainer(const T& container)
{
	size_t size = container.size();
	if (size <= 15)
	{
		for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		for (size_t i = 0; i < 15; i++)
		{
			std::cout << container[i] << " ";
		}
		std::cout << "[...] " << std::endl;
	}
}

class PmergeMe
{
	private:
		// Original input (unsorted data)
		std::vector<int> _vector;
		std::deque<int> _deque;

		// Core Algorithm
		void FJSortVector(std::vector<int> &vec);
		void FJSortDeque(std::deque<int> &deq);

		// Hierachy Building
		void sortVectorPairs(std::vector<std::pair<int, int>>& pairs);
		void sortDequePairs(std::deque<std::pair<int, int>>& pairs);

		// Jacobsthal Sequence
		std::vector<size_t> buildJacobsthalOrder(size_t n);
		std::deque<size_t> buildJacobsthalOrderDeq(size_t n);

		// Input Handling
		bool validateInput(char **argv);
		void parseInput(char **argv);

	public:
		PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &copy) = delete;
		PmergeMe &operator=(const PmergeMe &assign) = delete;
		~PmergeMe();

		void run();
};
