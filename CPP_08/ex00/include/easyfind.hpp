#pragma once

#include <iostream>
#include <algorithm>
#include <stdexcept>

#define RESET   "\033[0m"
#define MAGENTA "\033[35m"

template <typename T>
void easyfind(const T& container, int value)
{
	// auto lets the compiler figure out the type for you
	auto it = std::find(container.begin(), container.end(), value);

	// Value wasn't found
	if (it == container.end())
	{
		throw std::out_of_range("Value wasn't found");
	}
}