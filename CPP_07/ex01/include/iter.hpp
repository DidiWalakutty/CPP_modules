#pragma once

#include <iostream>

// No need for declaring size_t in template, as it's defined in iostream.
template <typename T, typename Func>
void iter(T* array, const size_t length, Func function)
{
	if (array == nullptr)
		return;
	for (size_t i = 0; i < length; i++)
	{
		std::cout << "Index: " << i << std::endl;
		function(array[i]);
		std::cout << std::endl;
	}
}

// const T&, so it can be used for both const and non-const arrays.
template <typename T>
void printElement(const T& element)
{
	std::cout << element << std::endl;
}

template <typename T>
void modifyNumber(T& element)
{
	std::cout << "original: ";
	printElement(element);
	element++;
	std::cout << "inremented:";
	printElement(element);
}

void modifyString(std::string& element)
{
	std::cout << "original: ";
	printElement(element);
	element += "_modified";
	std::cout << "modified: ";
	printElement(element);
}