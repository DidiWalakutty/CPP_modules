#include "../include/Serialization.hpp"
#include "../include/Data.hpp"
#include <iostream>

/*
	This project converts a pointer (memory address) to a numeric form (uintptr_t) and back.
	Useful when raw pointer addresses need to be stored or transferred as numbers.
*/
int main()
{
	Data data;
	data._number = 8;
	std::cout << std::endl;
	std::cout << "Data pointer created with number: " << data._number << std::endl;
	
	// Convert pointer to int
	uintptr_t raw = Serializer::serialize(&data);
	// Convert int back to Data*
	Data* ptr = Serializer::deserialize(raw);

	std::cout << std::endl;
	std::cout << "Original pointer: " << &data << std::endl;
	std::cout << "Serialized int: " << raw << std::endl;
	std::cout << "Deserialized pointer: " << ptr << std::endl;

	// Number check
	std::cout << std::endl;
	std::cout << "Number check for deserialized pointer: " << ptr->_number << std::endl;

	return (0);
}