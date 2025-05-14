/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/20 00:04:26 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/20 00:25:34 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Incorrect number of arguments." << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 is empty." << std::endl;
		return (1);
	}
	
	// reading files
	std::ifstream in_file(filename);
	if (!in_file)
	{
		std::cerr << "Error: Couldn't open file: " << filename << std::endl;
		return (1);
	}

	// writing files
	std::ofstream out_file(filename + ".replace");
	if (!out_file)
	{
		std::cerr << "Error: Couldn't create outfile: " << filename + ".replace" << std::endl;
		in_file.close();
		return (1);
	}
}