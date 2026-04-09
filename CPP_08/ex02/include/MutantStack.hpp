#pragma once

#include <stack>
#include <deque>

#define RESET   "\033[0m"
#define MAGENTA "\033[35m"

// If the container isn't specified, std::stack will use std::deque as the default container.
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack() = default;
		MutantStack(const MutantStack &copy) = default;
		MutantStack& operator=(const MutantStack& assign) = default;
		~MutantStack() = default;

		// Container could be std::deque, std::vector, std::list etc.
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}

		const_iterator begin() const
		{
			return this->c.begin();
		}

		const_iterator end() const
		{
			return this->c.end();
		}
};