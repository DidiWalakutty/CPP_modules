#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <string>
#include <fstream>

class Sed
{
	public:
		static std::string replacePiece(const std::string& content, const std::string& s1, const std::string& s2);
};

#endif