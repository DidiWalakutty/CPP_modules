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
		std::cout << "[...] ";
		std::cout << std::endl;
	}
}

class PmergeMe
{
	private:
		// contain OG input (unsorted data)
		std::vector<int> _vector;
		std::deque<int> _deque;

		// Sort Elements
		void FJSortVector(std::vector<int> &vec);
		void FJSortDeque(std::deque<int> &deq);

		// Creating Pairs
		void sortVectorPairs(std::vector<std::pair<int, int> >& pairs);
		void sortDequePairs(std::deque<std::pair<int, int> >& pairs);

		// Insert Pending/small Elements
		void insertPendingVecChain(std::vector<int> &mainChain, const std::vector<int> &pendChain);
		void insertPendingDeqChain(std::deque<int> &mainChain, const std::deque<int> &pendChain);

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
