#include "../include/Base.hpp"

int	main()
{
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