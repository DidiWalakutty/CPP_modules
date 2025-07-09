#include "../include/Serialization.hpp"
#include "../include/Data.hpp"

/*
  reinterpret_cast converts between pointer and integer types safely.
  A pointer (Data*) is a memory address.
  uintptr_t is an unsigned integer type guaranteed to hold pointer values without loss.
*/

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}