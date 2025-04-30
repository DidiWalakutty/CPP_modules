/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 17:39:59 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/30 18:01:32 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "[Invalid input]\n";
		std::cout << "Not enough arguments for Harl to complain!" << std::endl;
		return (0);
	}

	Harl harl;
	
	std::string level = argv[1];
	harl.complain(level);

	return (0);
}