/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarChecker.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:55:27 by agan              #+#    #+#             */
/*   Updated: 2024/06/06 18:55:28 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int is_int(std::string input)
{
	int i;

	i = 0;
	if (input[i] == '-')
		i++;
	if (!input[i])
		return 0;
	for (; input[i]; i++)
	{
		if (!std::isdigit(input[i]))
			break ;
	}
	if (!input[i] && i >= 1)
		return 1;
	return 0;
}

int is_double_or_float(std::string input)
{
	int i;

	i = 0;
	if (input[i] == '-')
		i++;
	if (!input[i])
		return 0;
	while (input[i])
	{
		if (!std::isdigit(input[i]))
			break ;
		i++;
	}
	if (input[i] == '.')
		i++;
	while (input[i])
	{
		if (!std::isdigit(input[i]))
			break ;
		i++;
	}
	if ((!input[i] || (input[i] == 'f' && !input[i + 1])) && \
		(input[i - 1] != '.'))
		return 1;
	else
		return 0;
}

e_type type_checker(std::string input)
{
	if (input.empty())
		return e_invalid;
	// check special
	if (input == "-inff" || input == "+inff" || input == "nanf" || \
		input == "-inf" || input == "+inf" || input == "nan")
		return e_special;
	// check int
	if (is_int(input))
		return e_int;
	// check float or double
	if (is_double_or_float(input))
	{
		if (input[input.size() - 1] == 'f')
			return e_float;
		else
			return e_double;
	}
	// check char
	if (input.length() == 1)
		return e_char;
	// if no match, return invalid
	return e_invalid;
}

