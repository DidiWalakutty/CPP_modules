/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 15:03:13 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/01 15:03:14 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	// Vector: dynamic array, used where you can quickly loop up any item by its position
	// You can instantly grab any item in the array.
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	// List: double linked list, where each item knows what comes before and after it.
	// Easy to insert/remove pieces anywhere, but must walk through full list
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	// Deque: double-ended dynamic array where you can quickly add + remove items
	// at both the front and back
	std::deque<int> deq;
	deq.push_back(42);
	deq.push_back(100);
	deq.push_back(7);

	std::cout << "Testing vector:" << std::endl;
	try
	{
		std::cout << "test 1" << std::endl;
		easyfind(vec, 20);
		std::cout << "Value found in vector!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Vector: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "test 2" << std::endl;
		easyfind(vec, 99);
		std::cout << "Value found in vector!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Vector: " << e.what() << std::endl;
	}

	std::cout << "\nTesting list:" << std::endl;
	try
	{
		std::cout << "test 1" << std::endl;
		easyfind(lst, 2);
		std::cout << "Value found in list!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "List: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "test 2" << std::endl;
		easyfind(lst, 8);
		std::cout << "Value found in list!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "List: " << e.what() << std::endl;
	}

	std::cout << "\nTesting deque:" << std::endl;
	try
	{
		std::cout << "test 1" << std::endl;
		easyfind(deq, 42);
		std::cout << "Value found in deque!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Deque: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "test 2" << std::endl;
		easyfind(deq, -1);
		std::cout << "Value found in deque!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Deque: " << e.what() << std::endl;
	}

	return 0;
}