#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>
#include <chrono>

class Base
{
	public:
		virtual ~Base();
};

// Creating empty classes that publicly inherit from Base
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);