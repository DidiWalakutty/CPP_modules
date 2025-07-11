#pragma once

#include <iostream>
#include <exception>	// std::bad_cast
#include <cstdlib>		// rand()
#include <ctime>		// time()

class Base
{
	public:
		virtual ~Base();
};

// Create empty classes that publicly inherit from Base
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);