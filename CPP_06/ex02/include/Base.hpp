#pragma once

class Base
{
	public:
		virtual ~Base();
};

// Create empty classes that publicly inherit from Base
class A : public Base {};
class B : public Base {};
class C : public Base {};

// Randomly instanties A, B or C and returns the instance as a Base pointer.
Base * generate(void);
// Prints the actual type of the object pointed to by p: A, B or C
void identify(Base* p);
// Prints the actual type of the object reference by p: A, B, or C.
// Looks at the actual object referred to and prints if it is A, B, or C.
// Can't use a pointer for this!!!
void identify(Base& p);