/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:20:56 by agan              #+#    #+#             */
/*   Updated: 2024/06/06 16:20:57 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void cast_float(std::string val);
void cast_double(std::string val);
void cast_int(e_type type, std::string val);

void cast_char(e_type type, std::string val, int x)
{
	char c;

	if (type == e_char)
		c = static_cast<char>(val[0]);
	else
		c = static_cast<char>(x);
	std::cout << "char: ";
	if (c > 32 && c < 127)
		std::cout << c << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	if (type == e_char)
	{
		std::stringstream ss;
		ss << (static_cast<int>(c));
		std::string new_val = ss.str();
		cast_int(type, new_val);
		cast_float(new_val);
		cast_double(new_val);
	}
}

void cast_int(e_type type, std::string val)
{
	std::stringstream ss (val);
	int num;

	if (ss >> num)
	{
		if (type == e_int)
			cast_char(type, val, num);
		std::cout << "int: " << num << std::endl;
	}
	else
	{
		if (type == e_int)
			cast_char(type, val, num);
		std::cout << "int: " << "impossible" << std::endl;
	}
}

void cast_float(std::string val)
{
	std::stringstream ss (val);
	float num;

	if (ss >> num)
		std::cout << "float: " << num << ((num != trunc(num)) ? "f" : ".0f") << std::endl;
	else
		std::cout << "float: " << "impossible" << std::endl;
}

void cast_double(std::string val)
{
	std::stringstream ss (val);
	double num;

	if (ss >> num)
		std::cout << "double: " << num << ((num != trunc(num)) ? "" : ".0") << std::endl;
	else
		std::cout << "double: " << "impossible" << std::endl;
}


void display(e_type type, std::string val)
{
	// if int -> cast int
	// if float -> cast float
	// if double -> cast double
		// each of them will check char
	// if char -> cast char and run the rest
	if (type == e_char)
		cast_char(type, val, 0);
	else
	{
		cast_int(type, val);
		cast_float(val);
		cast_double(val);
	}
}

void ScalarConverter::convert(std::string input)
{
    e_type type = type_checker(input);
    std::cout << "input type is ";
    if (type == e_char)
        std::cout << "e_char";
    else if (type == e_int)
        std::cout << "e_int";
    else if (type == e_special)
        std::cout << "e_special";
    else if (type == e_float)
        std::cout << "e_float";
    else if (type == e_double)
        std::cout << "e_double";
    else
        std::cout << "e_invalid";
    std::cout << std::endl;

    display(type, input);
}
