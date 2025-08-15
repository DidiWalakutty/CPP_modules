#include "../include/Base.hpp"


// Use nanoseconds since program start to avoid repeating patterns that otherwise would count per second.
int	main()
{
	std::srand(std::chrono::steady_clock::now().time_since_epoch().count());
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "\n--- Test #" << i + 1 << " ---" << std::endl;

		Base* obj = generate();

		std::cout << "id by pointer: ";
		identify(obj);
		std::cout << "id by reference: ";
		identify(*obj);

		delete obj;
	}
	return 0;
}