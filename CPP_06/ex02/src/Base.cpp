#include "../include/Base.hpp"

Base::~Base()
{
	std::cout << "Base Destructor was called" << std::endl;
}

/*
	Randomly creates and returns a new instance of A, B, or C as a Base pointer.
	Uses rand() to pick which derived class to instantiate.
*/
Base* generate()
{
	int r = std::rand() % 3;

	if (r == 0)
		return new A;
	else if (r == 1)
		return new B;
	else
		return new C;
}

/*
	Identifies the type of object pointed to by p using dynamic_cast.
	Returns nullptr if p is NOT of that type.
*/
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type found" << std::endl;
}

/* 
	Identifies the type of object referred to by p using dynamic_cast on references.
	A failed cast on reference always throws std::bad_cast, which is caught to try the next type.
	(void) is used to explicitly ignore the result of the cast and avoid compiler warnings,
	since we only care whether the cast succeeds — not the returned object.
*/
void identify(Base& p)
{
	try 
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;;
		return ;
	}
	catch (std::bad_cast&) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::bad_cast&) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::bad_cast&) {}

	std::cout << "Unknown type found" << std::endl;
}