#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

/*
	Each Dog/Cat gets a separate Brain with its own memory address.
	This means we can modify ideas per animal independently.

	Deep Copy: When using the copy constructor or assignment operator,
	we create a deep copy — a new Brain allocated at a different memory address,
	with the same ideas copied over.
*/
int	main()
{
	// {
	// 	std::cout << "\n--- Test 1: Subject example ---\n" << std::endl;
	// 	const Animal* j = new Dog();
	// 	const Animal* i = new Cat();
		
	// 	std::cout << std::endl;
	// 	delete j; // Should call Dog destructor (and delete its Brain)
	// 	delete i; // Should call Cat destructor (and delete its Brain)	
	// }
	// {
	// 	std::cout << "\n--- Test 2: Array of Animals ---\n" << std::endl;
	// 	const int size = 4; // Make it even, e.g., 4 → 2 Dogs + 2 Cats
	// 	const Animal* animals[size];

	// 	for (int i = 0; i < size; ++i) 
	// 	{
	// 		if (i < size / 2)
	// 			animals[i] = new Dog();
	// 		else
	// 			animals[i] = new Cat();
	// 	}

	// 	std::cout << "\n--- Deleting Animals ---\n" << std::endl;
	// 	for (int i = 0; i < size; ++i)
	// 		delete animals[i];
	// }
	// {
	// 	std::cout << "\n--- Test 3: Deep Copy Constructor Tests ---\n" << std::endl;
	// 	Dog a;
	// 	a.setIdea(0, "Bark at intruders.");
	// 	a.setIdea(1, "Roll over.");
	// 	std::cout << std::endl;

	// 	std::cout << UNDERLINE << "Testing Copy Constructor for Dog b: " << RESET << std::endl;
	// 	Dog b(a); // Copy constructor
	// 	b.setIdea(1, "Chew the sofa.");
	// 	std::cout << std::endl;

	// 	std::cout << "Dog a idea[0]: " << a.getIdea(0) << std::endl;
	// 	std::cout << "Dog b idea[0]: " << b.getIdea(0) << std::endl;
	// 	std::cout << std::endl;
	// 	std::cout << "Dog a idea[1]: " << a.getIdea(1) << std::endl;
	// 	std::cout << "Dog b idea[1]: " << b.getIdea(1) << std::endl;
	// 	std::cout << std::endl;

	// 	std::cout << "Brain address a: " << a.getBrain() << std::endl;
	// 	std::cout << "Brain address b: " << b.getBrain() << std::endl;
	// 	std::cout << std::endl;

	// 	std::cout << UNDERLINE << "Testing Assignment Constructor for Dog c: \n" << RESET << std::endl;
	// 	Dog c;
	// 	std::cout << std::endl;

	// 	c = a; // Assignment operator
	// 	c.setIdea(0, "Steal socks.");

	// 	std::cout << std::endl;
	// 	std::cout << "Dog a idea[0]: " << a.getIdea(0) << std::endl;
	// 	std::cout << "Dog c idea[0]: " << c.getIdea(0) << std::endl;
	// 	std::cout << std::endl;
	// 	std::cout << "Dog a idea[1]: " << a.getIdea(1) << std::endl;
	// 	std::cout << "Dog c idea[1]: " << c.getIdea(1) << std::endl;
	// 	std::cout << std::endl;
	// 	std::cout << "Brain address a: " << a.getBrain() << std::endl;
	// 	std::cout << "Brain address c: " << c.getBrain() << std::endl;
	// 	std::cout << std::endl;
	// }
	{
		std::cout << "\n--- Test 4: Full Brain Integrity at Scale ---\n" << std::endl;

		/* 
			Dog test 
		*/
		std::cout << BG_BLUE << "Dog Test" << RESET << std::endl;
		Dog ChewBakka;
		for (int i = 0; i < 20; ++i)
		{
			if (i % 2 == 0)
				ChewBakka.setIdea(i, "Food");
			else
				ChewBakka.setIdea(i, "SQUIRREL!");
		}

		std::cout << "Print Ideas up to 24" << std::endl;
		for (int i = 0; i < 24; ++i)
		{
			std::string idea = ChewBakka.getIdea(i);
			if (idea == "")
				std::cout << "ChewBakka's idea[" << i << "]: no clue..." << std::endl;
			else
				std::cout << "ChewBakka's idea[" << i << "]: " << idea << std::endl;
		}

		// Deep copy verification for Dog
		std::cout << UNDERLINE << "\nTesting Deep Copy for ChewBakka" << RESET << std::endl;
		Dog dogCopy = ChewBakka;
		dogCopy.setIdea(0, "Chase the ball");

		std::cout << "ChewBakka idea[0]: " << ChewBakka.getIdea(0) << std::endl;
		std::cout << "dogCopy idea[0]: " << dogCopy.getIdea(0) << std::endl;

		std::cout << "ChewBakka Brain address: " << ChewBakka.getBrain() << std::endl;
		std::cout << "dogCopy Brain address: " << dogCopy.getBrain() << std::endl;

		/* 
			Cat test 
		*/
		std::cout << BG_BLUE << "\nCat Test" << RESET << std::endl;
		Cat Salem;
		for (int i = 0; i < 100; ++i)
		{
			if (i % 3 == 0 && i % 5 == 0)
				Salem.setIdea(i, "Sit on the human's keyboard");
			else if (i % 3 == 0)
				Salem.setIdea(i, "Steal the cheese");
			else if (i % 5 == 0)
				Salem.setIdea(i, "Stare into the void after a long nap");
			else
				Salem.setIdea(i, "Plot World Domination");
		}

		for (int i = 0; i < 100; ++i)
		{
			std::cout << "Salem's idea[" << i << "]: " << Salem.getIdea(i) << std::endl;
		}

		// Deep copy verification for Cat
		std::cout << UNDERLINE << "\nTesting Deep Copy for Salem" << RESET << std::endl;
		Cat catCopy = Salem;
		catCopy.setIdea(0, "Climb the curtains");

		std::cout << std::endl;
		std::cout << "Salem idea[0]: " << Salem.getIdea(0) << std::endl;
		std::cout << "catCopy idea[0]: " << catCopy.getIdea(0) << std::endl;

		std::cout << std::endl;
		std::cout << "Salem Brain address: " << Salem.getBrain() << std::endl;
		std::cout << "catCopy Brain address: " << catCopy.getBrain() << std::endl;
		std::cout << std::endl;
	}
	return 0;
}