#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

/*
	An abstract class is a class that: can't be instantiated (create an obj from a class directly),
		is meant to be inherited from, has at least one pure virtual function.

	Virtual function: is a function thas has no implementation in the base class
		and must be overridden in derived classes (like makeSound).
*/
int main() 
{
    std::cout << "=== Polymorphic behavior ===\n" << std::endl;

    AAnimal* cat = new Cat();
    AAnimal* dog = new Dog();

    std::cout << UNDERLINE << "\nSounds from AAnimal pointers:" << RESET << std::endl;
	cat->makeSound();
    dog->makeSound();

    std::cout << UNDERLINE << "\nTypes:" << RESET << std::endl;
    std::cout << "Cat is a: " << cat->getType() << std::endl;
    std::cout << "Dog is a: " << dog->getType() << std::endl;
	std::cout << std::endl;

    delete cat;
    delete dog;

    // std::cout << "\n=== Instantiating AAnimal directly (should fail) ===" << std::endl;

    // Uncommenting the following line will cause a compiler error:
    // AAnimal a; // ❌ Error: cannot declare variable ‘a’ to be of abstract type ‘AAnimal’

    return 0;
}