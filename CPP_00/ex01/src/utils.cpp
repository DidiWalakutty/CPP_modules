/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@codam.student.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 22:13:42 by diwalaku      #+#    #+#                 */
/*   Updated: 2025/03/11 18:44:00 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include <iostream>

bool	Contact::spellingRules(const std::string &name, const std::string &type)
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

bool	Contact::phoneRules(const std::string &phone)
{
	size_t	dash_count = 0;
	size_t	digits = 0;
	size_t	i = 0;

	if (!std::isdigit(phone.back()))
		return (false);
	if (phone[0] == '+')
		i++;
	for (; i < phone.size(); i++)
	{
		char c = phone[i];
		if (c == '-')
			dash_count++;
		else if (std::isdigit(c))
			digits++;
		else
			return (false);
	}
	if (dash_count > 3 || digits < 7)
		return (false);
	return (true);
}

bool	Contact::secretRules(const std::string &secret)
{
	if (std::isspace(secret.front()) || std::isspace(secret.back()))
		return (false);
	for (char c : secret)
	{
		if (c == '\n' || c == '\t')
			return (false);
	}
	return (true);
}