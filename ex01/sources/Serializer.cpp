/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:47:06 by agan              #+#    #+#             */
/*   Updated: 2024/06/10 16:47:07 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Constructors
Serializer::Serializer()
{
	std::cout << "Serializer Default Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	std::cout << "Serializer Copy Constructor called" << std::endl;
	*this = copy;
}

// Destructor
Serializer::~Serializer()
{
	std::cout << "Serializer Destructor called" << std::endl;
}

// Operator overload
Serializer &Serializer::operator=(const Serializer &copy)
{
	std::cout << "Serializer Assignment operator called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
