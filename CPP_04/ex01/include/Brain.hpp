#pragma once

#include <iostream>
#include <string>
#include "../include/color.hpp"

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& assign);
		~Brain();

		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
};