/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/16 16:18:21 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/16 16:51:40 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

// c++ -Wall -Wextra -Werror -std=c++98 tester.cpp Fixed.cpp -o tester
// ./tester
int main() 
{
	// Tells std::cout to print true/false instead of 0/1
	std::cout << std::boolalpha;

	std::cout << "\n--- Constructors & Basic Output ---\n";
	Fixed a;
	Fixed const b(Fixed(6.06f) * Fixed(2));
	
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	std::cout << "\n--- Pre/Post Increment ---\n";
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a after pre-increment: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a after post-increment: " << a << std::endl;

	std::cout << "\n--- Pre/Post Decrement ---\n";
	Fixed e;
	std::cout << "e: " << e << std::endl;
	std::cout << "--e: " << --e << std::endl;
	std::cout << "e after pre-decrement: " << e << std::endl;
	std::cout << "e--: " << e-- << std::endl;
	std::cout << "e after post-decrement: " << e << std::endl;

	std::cout << "\n--- Arithmetic Operators ---\n";
	Fixed c(10);
	Fixed d(2);
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "c + d = " << c + d << std::endl;
	std::cout << "c - d = " << c - d << std::endl;
	std::cout << "c * d = " << c * d << std::endl;
	std::cout << "c / d = " << c / d << std::endl;

	std::cout << "\n--- Comparison Operators ---\n";
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "c > d: " << (c > d) << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "c >= d: " << (c >= d) << std::endl;
	std::cout << "c <= d: " << (c <= d) << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "c != d: " << (c != d) << std::endl;

	std::cout << "\n--- Conversion Functions ---\n";
	Fixed f(42.42f);
	Fixed g(42);
	std::cout << "f: " << f << ", g: " << g << std::endl;
	std::cout << "f.toInt(): " << f.toInt() << std::endl;
	std::cout << "f.toFloat(): " << f.toFloat() << std::endl;
	std::cout << "g.toInt(): " << g.toInt() << std::endl;
	std::cout << "g.toFloat(): " << g.toFloat() << std::endl;

	std::cout << "\n--- Static Min/Max Functions ---\n";
	const Fixed h(1.5f);
	const Fixed i(2.5f);
	Fixed j(3.5f);
	Fixed k(0.5f);
	std::cout << "h: " << h << ", i: " << i << std::endl;
	std::cout << "j: " << j << ", k: " << k << std::endl;
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "min(h, i): " << Fixed::min(h, i) << std::endl;
	std::cout << "max(j, k): " << Fixed::max(j, k) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

	return 0;
}
