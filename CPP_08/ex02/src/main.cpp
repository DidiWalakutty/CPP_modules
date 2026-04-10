/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 16:35:55 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/10 17:36:33 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	// --- Test 1 ---
	std::cout << MAGENTA << "1) --- Subject test: MutantStack ---" << RESET << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Top element: " << mstack.top() << std::endl;
	std::cout << "Current size: " << mstack.size() << std::endl;
	
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << "\n" << std::endl;
	std::cout << "Top element after pop: " << mstack.top() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	std::cout << "Testing iterator movement:" << std::endl;
	std::cout << "Current element: " << *it << std::endl;
	++it;
	std::cout << "After ++it: " << *it << std::endl;
	--it;
	std::cout << "After --it: " << *it << std::endl;
	
	std::cout << "\nElements in MutantStack:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	// Copying MutantStack to std::stack to demonstrate compatibility
	std::stack<int> s(mstack);
	// Avoid unused variable warning
	(void)s;


	// --- Test 2 ---
	std::cout << MAGENTA << "\n2) --- Same operations with std::list ---" << RESET << std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Last element: " << lst.back() << std::endl;

	lst.pop_back();

	std::cout << "Size after pop: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	std::cout << "Testing iterator movement:" << std::endl;
	std::cout << "Current element: " << *lit << std::endl;
	++lit;
	std::cout << "After ++lit: " << *lit << std::endl;
	--lit;
	std::cout << "After --lit: " << *lit << std::endl;

	std::cout << "\nFull iteration through std::list:" << std::endl;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	
	// --- Test 3 ---
	std::cout << MAGENTA << "\n3) --- Const iterator test ---" << RESET << std::endl;
	MutantStack<int> temp;

	temp.push(10);
	temp.push(20);

	const MutantStack<int> constStack(temp);
	MutantStack<int>::const_iterator cit = constStack.begin();
	MutantStack<int>::const_iterator cite = constStack.end();

	std::cout << "Elements in const MutantStack:" << std::endl;
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}
	
	// --- Test 4 ---
	// std::cout << MAGENTA << "\n4) --- Copy tests ---" << RESET << std::endl;
	// MutantStack<int> original;
	// original.push(1);
	// original.push(2);
	// original.push(3);

	// MutantStack<int> copy(original);
	// MutantStack<int> assigned;
	// assigned = original;

	// std::cout << "Original:" << std::endl;
	// for (MutantStack<int>::iterator i = original.begin(); i != original.end(); ++i)
	// 	std::cout << *i << std::endl;

	// std::cout << "Copy:" << std::endl;
	// for (MutantStack<int>::iterator i = copy.begin(); i != copy.end(); ++i)
	// 	std::cout << *i << std::endl;

	// std::cout << "Assigned:" << std::endl;
	// for (MutantStack<int>::iterator i = assigned.begin(); i != assigned.end(); ++i)
	// 	std::cout << *i << std::endl;
	
	return 0;
}