/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 18:05:01 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/14 20:04:07 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy)
{
	_stack = copy._stack;
}

RPN &RPN::operator=(const RPN &assign)
{
	if (this != &assign)
	{
		_stack = assign._stack;
	}
	return *this;
}

RPN::~RPN()
{
	// std::cout << MAGENTA << "BitcoinExchange object destroyed." << RESET << std::endl;
}

bool RPN::isOperator(char c) const
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	return false;
}

int RPN::calculateResult(int a, int b, char op) const
{
	switch (op)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '/':
			if (b == 0)
			{
				throw std::runtime_error("Dividing by 0 is not allowed");
			}
			return a / b;
		case '*':
			return a * b;
		default:
			throw std::runtime_error("Invalid Operator.");
	}
}

/**
 * @brief Validates and performs the RPN calculation based on the input string.
 * 
 *  1) Clears _stack to ensure it's empty
 *  2) Turns the input string into a stream (treats it like a file) and split it into tokens (by whitespace)
 *  3) For each token:
 * 		- If digit -> convert and push onto stack
 * 		- If operator -> pop two values, apply operation and push result
 * 		- Otherwise, throw and error.
 *  4) At the end, stack must contain exactly one value -> the result
 */
void RPN::check(const std::string &input)
{
	while (!_stack.empty())
		_stack.pop();

	// Turn the input string into a stream to read tokens one by one
	std::istringstream stream(input);
	std::string token;

	// Read each token (separated by whitespace)
	while (stream >> token)
	{
		// Case 1: single digit
		if (token.length() == 1 && isdigit(token[0]))
		{
			int num = token[0] - '0';
			_stack.push(num);
		}
		// Case 2: operator -> apply operation on top 2 values
		else if (token.length() == 1 && isOperator(token[0]))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Not enough numbers in stack for operation: " + token);
			
			int b = _stack.top(); // right operand
			_stack.pop();
			int a = _stack.top(); // left operand
			_stack.pop();

			int result = calculateResult(a, b, token[0]);
			_stack.push(result);
		}
		// Case 3: invalid token
		else
		{
			throw std::runtime_error("Invalid token: " + std::string(1, token[0]));
		}
	}
	// Should only have result in stack
	if (_stack.size() != 1)
		throw std::runtime_error("Invalid expression left");
	
	// Print result
	std::cout << _stack.top() << std::endl;
}