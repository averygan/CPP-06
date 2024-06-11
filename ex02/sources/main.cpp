/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:08:16 by agan              #+#    #+#             */
/*   Updated: 2024/06/10 18:08:16 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Instantiates A, B or C randomly and returns instance as a base pointer
Base * generate(void)
{
	std::srand(std::time(NULL));

	Base *pointer;
	int randomize = rand() % 3;

	switch(randomize) {
		case 0:
		{
			std::cout << "Creating A" << std::endl;
			return (pointer = new A);
		}
		case 1:
		{
			std::cout << "Creating B" << std::endl;
			return (pointer = new B);
		}
		case 2:
		{
			std::cout << "Creating C" << std::endl;
			return (pointer = new C);
		}
		default:
			return (pointer = NULL);
	}
}

// Prints actual type of object pointed to by p
void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "Type: A" << std::endl;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "Type: B" << std::endl;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "Type: C" << std::endl;
	}
	else
	{
		std::cout << "Type: Unknown" << std::endl;
	}
}

// Prints actual type of object pointed to by p
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Type: A" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Type: B" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Type: C" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{}
	std::cout << "Type: Unknown" << std::endl;
}

void print_test(std::string string)
{
	std::cout << GREEN << std::endl << string << std::endl;
	for (int i = 0; i < 30; i++)
		std::cout << "-";
	std::cout << RESET << std::endl;
}

int main(void)
{
	// // Created class D to test for invalid type
	// class D : public Base
	// {};
	// D d_obj;

	print_test("GENERATING RANDOM PTR");
	Base *ptr = generate();
	A a_obj;
	B b_obj;
	C c_obj;

	print_test("IDENTIFYING TYPE OF RANDOM PTR");
	identify(ptr);
	identify(*ptr);

	print_test("IDENTIFYING TYPES: EXPECTED A, B, C");
	identify(a_obj);
	identify(b_obj);
	identify(c_obj);

	// print_test("IDENTIFYING TYPES: EXPECTED UNKNOWN");
	// identify(d_obj);

	print_test("END OF TESTS");
	delete (ptr);
}

