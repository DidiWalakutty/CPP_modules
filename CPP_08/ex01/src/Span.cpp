/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/30 21:30:28 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/03/30 22:26:33 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int N) : _maxSize(N) {};

Span::Span(const Span &copy) : _maxSize(copy._maxSize), _elementNum(copy._elementNum) {};

Span &Span::operator=(const Span &assign)
{
	if (this != &assign)
	{
		_maxSize = assign._maxSize;
		_elementNum = assign._elementNum;
	}
	return *this;
}

Span::~Span()
{
	// std::cout << RED << "Destructor was called" << RESET << std::endl;
}

void Span::addNumber(int num)
{
	if (_elementNum.size() >= _maxSize)
		throw std::out_of_range("Can't add more numbers, container has reached capacity.");

	_elementNum.push_back(num);
}

unsigned int Span::longestSpan() const
{
	if (_elementNum.size() < 2)
	{
		throw std::out_of_range("Not enough elements to check longest span");
	}
	
	auto smallest = *std::min_element(_elementNum.begin(), _elementNum.end());
	auto largest = *std::max_element(_elementNum.begin(), _elementNum.end());

	return (largest - smallest);
}

unsigned int Span::shortestSpan() const
{
	if (_elementNum.size() < 2)
	{
		throw std::out_of_range("Not enough elements to check shortest span");
	}

	auto copy = this->_elementNum;
	std::sort(copy.begin(), copy.end());
	unsigned int min_span = copy[1] - copy[0];

	for (size_t i = 2; i < copy.size(); i++)
	{
		int span = copy[i] - copy[i - 1];
		if (span < min_span)
			min_span = span;
	}
	return min_span;	
}