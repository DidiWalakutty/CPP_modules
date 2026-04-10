/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/30 21:30:28 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/10 17:49:45 by diwalaku      ########   odam.nl         */
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

// Add a single number to the container
void Span::addNumber(int num)
{
	if (_elementNum.size() >= _maxSize)
		throw std::out_of_range("Can't add more numbers, container has reached capacity.");

	_elementNum.push_back(num);
}

/**
 *  Adds a range of numbers to Span using iterators.
 *  vectorSize calculates how many elements are between the begin and end iterators.
 *  Checks size of what's currently in the container + size of the new vector.
 *  If the total > _maxSize, throws an exception.
 *  If not, append them to the end of the container.
 */
void Span::addMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	int vectorSize = std::distance(begin, end);
	std::cout << "Distance between iterators: " << vectorSize << std::endl;
	std::cout << "Current container size: " << _elementNum.size() << std::endl;
	int totalSize = _elementNum.size() + vectorSize;
	std::cout << "Total size after adding: " << totalSize << std::endl;
	if (_elementNum.size() + vectorSize > _maxSize)
		throw std::out_of_range("Couldn't add multiple numbers, container would reach or go over capacity.");
	
	_elementNum.insert(_elementNum.end(), begin, end);
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
	unsigned int minimal_span = copy[1] - copy[0];

	for (size_t i = 2; i < copy.size(); i++)
	{
		unsigned int current_span = copy[i] - copy[i - 1];
		if (current_span < minimal_span)
			minimal_span = current_span;
	}
	return minimal_span;	
}