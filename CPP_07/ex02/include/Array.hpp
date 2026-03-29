#pragma once

#include <iostream>
#include <stdexcept>

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

template <typename T> 
class Array
{
	private:
		T*	_data;
		unsigned int _arraySize;
	
	public:

		// Default Constructor
		Array() : _data(nullptr), _arraySize(0)
		{
			std::cout << GREEN << "Default Constructor called" << RESET << std::endl;
		}

		// Constructor with parameter
		Array(unsigned int n)
		{
			std::cout << YELLOW << "Constructor with unsign. int parameter was called" << RESET << std::endl;
			_data = new T[n];
			_arraySize = n;
		}

		// Copy Constructor (copy of existing object + allocating new memory for it)
		Array(const Array& copy)
		{
			std::cout << BLUE << "Copy Constructor was called" << RESET << std::endl;
			_arraySize = copy._arraySize;
			_data = new T[_arraySize];

			for (unsigned int i = 0; i < _arraySize; i++)
				_data[i] = copy._data[i];
		}
		
		// Copy Assignment Operator (copies contents of one object into another already existing object)
		Array& operator=(const Array& assign)
		{
			std::cout << MAGENTA << "Copy Assignment Operator was called" << RESET << std::endl;
			
			// Compare addresses + prevent self-assignment (a = a), which would delete data before copying it
			if (this != &assign)
			{
				delete[] _data;	// Delete existing memory
				_arraySize = assign._arraySize;
				_data = new T[_arraySize];
			
				for (unsigned int i = 0; i < _arraySize; i++)
					_data[i] = assign._data[i];
			}
			return *this;
		}

		// Destructor
		~Array()
		{
			delete[] _data;
			std::cout << RED << "Destructor was called" << RESET << std::endl;

		}

		unsigned int size() const
		{
			return _arraySize;
		}

		// Custom classes don't support [] by default, so we overload operator[]
		// to define how elements are accessed using arr[index].
		// This works automatically for built-in arrays and pointers, but not for custom classes.

		// Non-const version: allows modification of elements
		T& operator[](unsigned int index)				
		{
			if (index >= _arraySize)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
		}

		// Const version: read-only access for const objects
		const T& operator[](unsigned int index) const
		{
			if (index >= _arraySize)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
		}
};
