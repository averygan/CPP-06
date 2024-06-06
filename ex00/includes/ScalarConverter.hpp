/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:20:40 by agan              #+#    #+#             */
/*   Updated: 2024/06/06 16:20:41 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <string>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <sstream>
#include <cmath>

# define BROWN "\033[1;33m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define BLUE	"\033[1;34m"
# define CYAN	"\033[1;36m"
# define RESET "\033[0m"

# define BROWN_R "\033[33m"
# define RED_R "\033[31m"
# define GREEN_R "\033[32m"
# define BLUE_R	"\033[34m"
# define CYAN_R	"\033[36m"

enum e_type {e_char, e_int, e_float, e_double, e_special, e_invalid};

class ScalarConverter
{
private:
	// // Constructors
	// ScalarConverter();
	// ScalarConverter(const ScalarConverter &copy);
	// // Destructor
	// ~ScalarConverter();
	// // Operator overload
	// ScalarConverter &operator=(const ScalarConverter &copy);

public:
	static void convert(const std::string input);
};

int		is_int(std::string input);
int		is_double_or_float(std::string input);
e_type	type_checker(std::string input);
void 	cast_float(std::string val);
void 	cast_double(std::string val);
void 	cast_int(e_type type, std::string val);

#endif