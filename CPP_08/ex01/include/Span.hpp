#pragma once

// Reset
#define RESET       "\033[0m"

// Text colors
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

#include <iostream>
#include <vector>

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
		
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};