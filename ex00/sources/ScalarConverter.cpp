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

// Constructors
ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout << "ScalarConverter Copy Constructor called" << std::endl;
	*this = copy;
}

// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor called" << std::endl;
}

// Operator overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	std::cout << "ScalarConverter Assignment operator called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}

/* if char type -> cast 
- if type != char, check if within char min/max and cast 
	- if displayable, print c
	- if non-displayable, print err */
void cast_char(e_type type, std::string val, int x)
{
	char c;

	std::cout << "char: ";
	if (type == e_char)
		c = static_cast<char>(val[0]);
	else if (x >= CHAR_MIN && x <= CHAR_MAX)
		c = static_cast<char>(x);
	else
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (c > 32 && c < 127)
		std::cout << c << std::endl;
	else
		std::cout << "non displayable" << std::endl;
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
		if (type != e_char)
			cast_char(type, val, num);
		std::cout << "int: " << num << std::endl;
	}
	else
	{
		if (type != e_char)
			cast_char(type, val, num);
		std::cout << "int: " << "impossible" << std::endl;
	}
}

void cast_float(std::string val)
{
	std::stringstream ss (val);
	float num;

	if (ss >> num)
	{
		std::cout << "float: " << std::setprecision(7) << \
			num << ((num != trunc(num)) ? "f" : ".0f") << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;
}

void cast_double(std::string val)
{
	std::stringstream ss (val);
	double num;

	if (ss >> num)
	{
		std::cout << "double: " << std::setprecision(15) << \
			num << ((num != trunc(num)) ? "" : ".0") << std::endl;
	}
	else
		std::cout << "double: impossible" << std::endl;
}

void printer(std::string type, std::string msg)
{
	std::cout << type << msg << std::endl;
}

// Handle inf and nan with/without f suffix
void special_handler(std::string val)
{
	printer("char: ", "impossible");
	printer("int: ", "impossible");
	if (val.substr(1, 3) == "inf")
	{
		printer("float: ", val.substr(0, 4) + "f");
		printer("double: ", val.substr(0, 4));
	}
	else if (val.substr(0, 3) == "nan")
	{
		printer("float: ", "nanf");
		printer("double: ", "nan");
	}
}

// if special -> print from special handler
// if int -> cast int
// if float -> cast float
// if double -> cast double
	// each of them will check char
// if char -> cast char and run the rest
void display(e_type type, std::string val)
{
	if (type == e_special)
		special_handler(val);
	else if (type == e_char)
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

    if (type != e_invalid)
    	display(type, input);
    else
    	std::cout << RED << "invalid argument: not type of char/int/float/double" 
    	<< RESET << std::endl;
}
