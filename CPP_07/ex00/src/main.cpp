/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 15:02:58 by diwalaku      #+#    #+#                 */
/*   Updated: 2026/04/01 15:02:59 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/whatever.hpp"
#include <iostream>

// :: is the scope resolution operator: use this function from the global scope
int main( void ) 
{
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	char e = '<';
	char f = '>';
	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

	return 0;
}