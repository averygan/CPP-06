/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:29:22 by agan              #+#    #+#             */
/*   Updated: 2024/06/10 17:29:23 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data = {42};
	Data *data_ptr = &data;
	Data *deserialized;
	uintptr_t serialized;

	// before serializing data ptr
	std::cout << std::setw(WIDTH) 
		<< "original pointer: " << &data << std::endl;

	// serialize data ptr
	serialized = Serializer::serialize(data_ptr);
	std::cout << std::setw(WIDTH)
		<< "serialized: " << serialized << std::endl;

	// deserialize ptr
	deserialized = Serializer::deserialize(serialized);
	std::cout << std::setw(WIDTH)
		<< "deserialized: " << deserialized << std::endl;

	// deserialize value
	deserialized = Serializer::deserialize(serialized);
	std::cout << std::setw(WIDTH)
		<< "deserialized value: " << deserialized->value << std::endl;
}
