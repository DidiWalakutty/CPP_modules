/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 16:42:36 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/04 19:19:42 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

// std:: refers to the standard C++ library (e.g. std::string, std::cout).
// We assign argv[i] to a std::string called str.
// str.length() gives the number of characters in the string.
// std::toupper returns an int, so we use static_cast<char> to safely convert it back to a char.
// std::cout prints each uppercase character to the terminal.
int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (size_t j = 0; j < str.length(); j++)
				std::cout << static_cast<char>(std::toupper(str[j]));
		}
		std::cout << std::endl;
	}
	return (0);
}