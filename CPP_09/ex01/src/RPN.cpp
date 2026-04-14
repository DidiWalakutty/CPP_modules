/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 18:05:01 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/14 19:40:08 by diwalaku      ########   odam.nl         */
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
 *  2) Turns the input string into a stream (treats it like a file)
 *  3) Variable 'token' will store one piece of the input at a time
 *  4) Loops through each token in the input string:
 *     - token length must be 1 and either a digit or operator
 *     - If digit, convert to int and push onto _stack
 *     - If operator, check if at least 2 numbers are in _stack
 *       
 * 
 * @param input The RPN expression as a string.
 * @throw std::runtime_error if input is invalid or not enough numbers in stack
 */
void RPN::check(const std::string &input)
{
	while (!_stack.empty())
		_stack.pop();

	// takes input as string and splits it by whitespace into tokens.
	// turns the input string into a stream (treat the string like a file).
	// token is a string variable that'll store one piece at a time.
	std::istringstream stream(input);
	std::string token;

	// Loop through each token in the input string
	// reads one word/token at a time from the stream into the variable 'token'.
	// >> means: read the next chunk of text until you hit whitespace.
	while (stream >> token)
	{
		if (token.length() == 1 && isdigit(token[0]))
		{
			int num = token[0] - '0';
			_stack.push(num);
		}
		else if (token.length() == 1 && isOperator(token[0]))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Not enough numbers in stack for operation: " + token);
			
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();

			int result = calculateResult(a, b, token[0]);
			_stack.push(result);
		}
		else
		{
			throw std::runtime_error("Invalid token: " + std::string(1, token[0]));
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Invalid expression left");
	
	std::cout << _stack.top() << std::endl;
}