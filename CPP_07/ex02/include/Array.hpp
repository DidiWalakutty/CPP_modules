#pragma once

template <typename T> 
class Array
{
	private:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array& operator=(const Array& assign);
		~Array();
};
