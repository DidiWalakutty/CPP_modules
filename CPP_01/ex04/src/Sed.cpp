/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sed.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/22 18:16:53 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/04/22 18:31:25 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Sed.hpp"

// Returns a new string where all s1 occurences are replaced by s2.
// string::npos - no position. Loop runs as long as we keep finding s1 in the text.
std::string replace_string(const std::string& text, const std::string& s1, const std::string& s2)
{
	// 1. Search for the first occurence of s1 using .find()
	// 2. Copy all text before that occurence to the result.
	// 3. Add s2 instead of s1
	// 4. Move the search start position to just after the occurence
	// 5. Repeat unfil .find() returns :std::string::npos
	// 6. Append anything remaining at the end

	std::string result;
	size_t		pos = 0;
	size_t		found = text.find(s1, pos);

	while (found != std::string::npos)
	{
		// Appends the part of the string before the found s1.
		result.append(text.substr(pos, found - pos));
		// Replace s1 with s2.
		result.append(s2);
		// Update our position in our text
		pos = found + s1.length();
		// Search for s1 again, starting from our current pos
		found = text.find(s1, pos);
	}
	// Add whatever is left at the end of the OG text.
	result.append(text.substr(pos));
	return (result);
}