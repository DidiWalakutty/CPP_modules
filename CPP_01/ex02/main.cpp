/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/11 17:00:46 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/11 17:59:52 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// This program demonstrates the use of a string, a pointer to the string,
// and a reference to the string.
// - `str` is a string variable initialized to "HI THIS IS BRAIN".
// - `stringPTR` is a pointer that holds the address of `str`.
// - `stringREF` is a reference that refers directly to `str`.
// The program prints the memory addresses and values of all three, 
// which should be the same for all of them.
int	main()
{
	std::string original = "HI THIS IS BRAIN";

	std::string *stringPTR = &original;
	std::string &stringREF = original;

	std::cout << "The memory address of string is: " << &original << std::endl;
	std::cout << "The memory address held by stringPTR is: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF is: " << &stringREF << std::endl;

	std::cout << "The value of string is: " << original << std::endl;
	std::cout << "The value pointed to by stringPTR is: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF is: " << stringREF << std::endl;
	return (0);
}