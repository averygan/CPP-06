/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:47:10 by agan              #+#    #+#             */
/*   Updated: 2024/06/10 16:47:11 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <string>
#include <cstdlib>
#include <iostream>
#include <stdint.h>
#include <iomanip>
#include "Data.hpp"

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

# define WIDTH 20

class Serializer {
// private:
	// // Constructors
	// Serializer();
	// Serializer(const Serializer &copy);
	// // Destructor
	// ~Serializer();
	// // Operator overload
	// Serializer &operator=(const Serializer &copy);

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif