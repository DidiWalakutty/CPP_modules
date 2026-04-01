/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 15:02:47 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/01 15:02:50 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"
#include <iostream>

int main()
{
	int int_array[] = {11, 22, 33, 44, 55};
	const int Const_Int_Array[] = {68, 77, 88, 91, 102};

	float floatArray[] = {20.1f, 21.1f, 22.1f};

	std::string string_array[] = {"The", "road", "goes", "ever", "on"};
	const std::string const_string_array[] = {"Not", "all", "those", "that", "wander", "are", "lost"};

	// function template functions need to be explicitly instantiated when passed
	// as function parameters with the type we'll use.
	std::cout << "--- Handling Int Array ---" << std::endl;
	iter(int_array, 5, modifyNumber<int>);

	std::cout << "--- Handling Const Int Array ---" << std::endl;
	std::cout << "! printing only !" << std::endl;
	iter(Const_Int_Array, 5, printElement<int>);
	
	std::cout << "--- Handling String Array ---" << std::endl;
	iter(string_array, 5, modifyString);

	std::cout << "--- Handling Const String Array ---" << std::endl;
	std::cout << "! printing only !" << std::endl;
	iter(const_string_array, 7, printElement<std::string>);

	std::cout << "--- Handling Float Array ---" << std::endl;
	iter(floatArray, 3, modifyNumber<float>);

}