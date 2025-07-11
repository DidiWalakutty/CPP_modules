#pragma once

#include <cstdint>

class Data;	// Forward declaration

class Serializer
{
	private:
		Serializer() = delete;
		Serializer(const Serializer& assign) = delete;
		Serializer& operator=(const Serializer& copy) = delete;
		~Serializer() = delete;

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
