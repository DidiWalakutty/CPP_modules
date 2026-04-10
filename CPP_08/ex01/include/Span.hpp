#pragma once

#include <iostream>
#include <vector>

#define RESET       "\033[0m"
#define MAGENTA     "\033[35m"

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _elementNum;

	public:
		Span() = delete;
		Span(unsigned int N);
		Span(const Span &copy);
		Span& operator=(const Span& assign);
		~Span();

		void addNumber(int num);
		void addMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};