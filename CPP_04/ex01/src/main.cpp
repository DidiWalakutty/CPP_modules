#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"

/*
	Each Dog/Cat gets a separate Brain with its own memory address.
	This means we can modify ideas per animal independently.

	Deep Copy: When using the copy constructor or assignment operator,
	we create a deep copy — a new Brain allocated at a different memory address,
	with the same ideas copied over.
*/
int	main()
{
	{
		std::cout << "\n--- Test 1: Array of Animals ---\n" << std::endl;
		const int size = 4; // Make it even, e.g., 4 → 2 Dogs + 2 Cats
		const Animal* animals[size];

		for (int i = 0; i < size; ++i) 
		{
			if (i < size / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		std::cout << std::endl;
		for (int i = 0; i < size; i++)
		{
			animals[i]->makeSound();
		}
	
		std::cout << "\n--- Deleting Animals ---\n" << std::endl;
		for (int i = 0; i < size; ++i)
			delete animals[i];
	}
	{
		std::cout << "\n--- Test 2: Cat Deep Copy and Brain Integrity ---\n" << std::endl;

		// Create original Cat and fill ideas
		Cat PurrBakka;
		for (int i = 0; i < 100; ++i)
		{
			if (i % 3 == 0 && i % 5 == 0)
				PurrBakka.setIdea(i, "Sit on the human's keyboard");
			else if (i % 3 == 0)
				PurrBakka.setIdea(i, "Steal the cheese");
			else if (i % 5 == 0)
				PurrBakka.setIdea(i, "Stare into the void after a long nap");
			else
				PurrBakka.setIdea(i, "Plot World Domination");
		}

		for (int i = 0; i < 100; ++i)
		{
			std::cout << "PurrBakka's idea[" << i << "]: " << PurrBakka.getIdea(i) << std::endl;
		}

		// Copy constructor test
		std::cout << UNDERLINE << "\nTesting Copy Constructor for catCopy:" << RESET << std::endl;
		Cat catCopy(PurrBakka);

		// Change some ideas in copy
		catCopy.setIdea(0, "Climb the curtains");
		catCopy.setIdea(15, "Nap all day");

		// Show that original is unaffected
		std::cout << "\nAfter modifying catCopy's ideas:" << std::endl;
		std::cout << "PurrBakka idea[0]: " << PurrBakka.getIdea(0) << std::endl;
		std::cout << "catCopy idea[0]: " << catCopy.getIdea(0) << std::endl;
		std::cout << std::endl;
		std::cout << "PurrBakka idea[15]: " << PurrBakka.getIdea(15) << std::endl;
		std::cout << "catCopy idea[15]: " << catCopy.getIdea(15) << std::endl;

		// Show brain addresses to prove deep copy
		std::cout << "\nBrain addresses:" << std::endl;
		std::cout << "PurrBakka Brain address: " << PurrBakka.getBrain() << std::endl;
		std::cout << "catCopy Brain address: " << catCopy.getBrain() << std::endl;
		std::cout << std::endl;
	}
	return 0;
}