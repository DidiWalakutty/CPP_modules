#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

// When using 'new' you alloc on the heap, so you need to call 'delete' yourself.

/*
	Polymorphism lets us use a base class pointer or reference to call functions from a derived class.
	This works because of virtual functions — the program figures out which function to call at runtime.
	It helps write flexible code that works with different types of animals, for example.
	Without virtual functions, it would always call the base class version instead.
*/
int	main()
{
	// Subject Main Test will have leaks, because it's not using delete
	// {
	// 	std::cout << BG_MAGENTA << "\n--- Subject's Main Test ---\n" << RESET << std::endl;
		

	// 	const Animal* meta = new Animal();
	// 	const Animal* j = new Dog();
	// 	const Animal* i = new Cat();

	// 	std::cout << j->getType() << " " << std::endl;
	// 	std::cout << i->getType() << " " << std::endl;

	// 	i->makeSound();
	// 	j->makeSound();
	// 	meta->makeSound();
	// }
	{
		std::cout << BG_CYAN << "\n--- Regular Polymorphism test ---\n" << RESET << std::endl;

		const Animal* basic = new Animal();
		const Animal* doggie = new Dog();
		const Animal* kitty = new Cat();

		std::cout << "\nBasic's animal type: " << basic->getType() << std::endl;
		std::cout << "Doggie's animal type: " << doggie->getType() << std::endl;
		std::cout << "Kitty's animal type: " << kitty->getType() << std::endl;

		std::cout << "\nBasic's sound: " << std::endl;
		basic->makeSound();
		std::cout << "\nDoggie's sound: " << std::endl; 
		doggie->makeSound();
		std::cout << "\nKitty's sound: " << std::endl; 
		kitty->makeSound();
		std::cout << std::endl;

		delete basic;
		delete doggie;
		delete kitty;
	}
	// {
	// 	std::cout << BG_GREEN << "\n--- WrongAnimal Polymorphism Test ---\n" << RESET << std::endl;

	// 	const WrongAnimal* wrong = new WrongCat();

	// 	std::cout << "\nWrongCat type: " << wrong->getType() << "\n" << std::endl;
	// 	wrong->makeSound(); // Will wrongly call WrongAnimal’s sound, because makeSound isn't virtual

	// 	delete wrong;
	// }
	// {
	// 	std::cout << BG_YELLOW << "\n--- Copy Constructor & Assignment Test ---\n" << RESET << std::endl;

	// 	Cat original;
	// 	std::cout << std::endl;

	// 	Cat copied(original);
	// 	std::cout << std::endl;
		
	// 	Cat assigned;
	// 	std::cout << std::endl;
		
	// 	assigned = original;
	// 	std::cout << std::endl;

	// 	copied.makeSound();
	// 	assigned.makeSound();
	// 	std::cout << std::endl;
	// }
	return 0;
}