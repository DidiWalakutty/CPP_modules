/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 22:13:42 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/03/06 23:15:52 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

bool	Contact::spellingrules(const std::string &name, const std::string &type)
{
	if (std::isspace(name.front()) || std::isspace(name.back()))
		return (false);
	for (char c : name)	// range-based loop that loops through each char of name
	{
		if (type == "first" || type == "last")
		{
			if (!std::isalpha(c) && !std::isspace(c))
			{
				if (type == "last" && c == '-')
					continue ;
				return (false);
			}
		}
		if (type == "nickname")
		{
			if (!std::isalnum(c) && !std::ispunct(c) && !std::isspace(c))
				return (false);
		}
	}
	return (true);
} 

bool	Contact::phonerules(const std::string &phone)
{
	size_t	dash_count = 0;
	size_t	digits = 0;

	if (phone.empty())
		return (false);
	

	for (char c : phone)
	{
		if (index == 0 && c == '+')
			index++;
		if (!std::isdigit(c) && c != '-')
			return (false);
		if (c == '-')
			dash_count++;
		if (std::isdigit(c))
			digits++;
		index++;
	}
	if (dash_count > 3 || digits < 7)
		return (false);
	return (true);
}