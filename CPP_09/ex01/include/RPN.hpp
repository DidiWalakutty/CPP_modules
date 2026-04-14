#pragma once

#include <iostream>
#include <sstream>
#include <stack>

#define RESET   "\033[0m"
#define MAGENTA "\033[35m"
#define RED	 	"\033[31m"

class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &assign);
		~RPN();

		void check(const std::string &input);
		bool isOperator(char c) const;
		int calculateResult(int a, int b, char op) const;

};