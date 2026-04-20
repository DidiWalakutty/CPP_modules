#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <chrono>
#include <algorithm>

template <typename T>
void printContainer(const T& container)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

class PmergeMe
{
	private:
		// contain OG input (unsorted data)
		std::vector<int> _vector;
		std::deque<int> _deque;

		// Sort Big Elements
		void FJSortVector(std::vector<int> &vec);
		void FJSortDeque(std::deque<int> &deq);

		// Insert Small Elements
		void FJMergeInsertVector(std::vector<int> &mainChain, const std::vector<int> &pendChain);
		void FJMergeInsertDeque(std::deque<int> &mainChain, const std::deque<int > &pendChain);

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
