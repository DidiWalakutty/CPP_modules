/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
<<<<<<< HEAD
/*   Created: 2025/04/20 00:04:26 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/20 00:25:34 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sed.hpp"

=======
/*   Created: 2025/04/22 17:18:55 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/05/01 18:00:45 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Sed.hpp"

// Uses ifstream to try opening the file.
// seekg moves the read position to end; tellg gets file size.
// std::ios is a class inside std:input/outputstream and end accesses the last constant.
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
// ifstream opens the file in readmode, ofstream creates a file for writing or overwrites.
// istreambuf_iterator reads every char of infile from start until EOF and stores it in content.
>>>>>>> b7fc9b57c89d2cecb962810bfe636aefbe296165
int	main(int argc, char **argv)
{
	if (argc != 4)
	{
<<<<<<< HEAD
		std::cerr << "Error: Incorrect number of arguments." << std::endl;
		return (1);
	}

=======
		std::cerr << "Error: Input is incorrect." << std::endl;
		return (1);
	}
>>>>>>> b7fc9b57c89d2cecb962810bfe636aefbe296165
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

<<<<<<< HEAD
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
=======
	if (check_input(filename, s1) == 1)
		return (1);

	std::ifstream infile(filename);
	std::string content((std::istreambuf_iterator<char>(infile)),
							std::istreambuf_iterator<char>());
	infile.close();

	std::string replaced = replace_string(content, s1, s2);
	if (replaced.empty())
	{
		std::cerr << "Error: Couldn't create replacement string." << std::endl;
		return (1);
	}

	std::ofstream outfile(filename + ".replace");
	if (!outfile)
	{
		std::cerr << "Error: Couldn't create output file." << std::endl;
		return (1);
	}
	outfile << replaced;
	outfile.close();
	return (0);
>>>>>>> b7fc9b57c89d2cecb962810bfe636aefbe296165
}