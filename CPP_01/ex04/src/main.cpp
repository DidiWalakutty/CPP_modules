/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/22 17:18:55 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/22 18:16:51 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Sed.hpp"

// ifstream reads from files.
// seekg(0, std::ios::end) moves the pointer to the end of the file.
// tellg() returns the pointer's position, which is the file size when at the end.
static int	check_input(const std::string& filename, const std::string& s1)
{
	if (s1.empty())
	{
		std::cerr << "Error: s1 can't be empty." << std::endl;
		return (1);
	}
	std::ifstream infile(filename);
	if (!infile)
	{
		std::cerr << "Error: Couldn't open textfile." << std::endl;
		return (1);
	}
	infile.seekg(0, std::ios::end);
	if (infile.tellg() == 0)
	{
		std::cerr << "Error: Textfile is empty." << std::endl;
		return (1);
	}
	infile.close();
	return (0);
}

// s2 can be empty, we remove every s1 occurence.
// we need to be able to open filename.
int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Input is incorrect." << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (check_input(filename, s1) == 1)
		return (1);

	// Open the input file to read content
	std::ifstream infile(filename);

	// Read the entire content of the file into the 'content' string one char at a time.
	// The istreambuf_iterator creates an iterator at the start end end of the file.
	std::string content((std::istreambuf_iterator<char>(infile)),
							std::istreambuf_iterator<char>());
	infile.close();

	std::string replaced = replace_string(content, s1, s2);

	std::ofstream outfile(filename + ".replace");
	if (!outfile)
	{
		std::cerr << "Error: Couldn't create output file." << std::endl;
		return (1);
	}
	outfile << replaced;
	outfile.close();
	return (0);
}