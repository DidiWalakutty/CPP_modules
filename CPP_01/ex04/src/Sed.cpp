/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sed.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/22 18:16:53 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/30 15:50:22 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Sed.hpp"

// Replaces all occurrences of s1 with s2 in text.
// Loops through text, copying everything before each s1 match to result.
// At each match, appends s2 instead of s1.
// Stops when .find() returns std::string::npos (not found).
// Appends the rest of the text after the last match.
std::string replace_string(const std::string& text, const std::string& s1, const std::string& s2)
{
	std::string result;
	size_t		pos = 0;
	size_t		found = text.find(s1, pos);

	while (found != std::string::npos)
	{
		result.append(text.substr(pos, found - pos));
		result.append(s2);
		pos = found + s1.length();
		found = text.find(s1, pos);
	}
	result.append(text.substr(pos));
	return (result);
}