/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:06:08 by tmatis            #+#    #+#             */
/*   Updated: 2021/08/26 15:19:18 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <iostream>

Base *generate(void)
{
	//generate random number form 0 to 2
	switch (rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

void	identify(Base *base)
{
	A *a = dynamic_cast<A *>(base);
	if (a)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	B *b = dynamic_cast<B *>(base);
	if (b)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	C *c = dynamic_cast<C *>(base);
	if (c)
	{
		std::cout << "C" << std::endl;
		return ;
	}
}

void	identify(Base &base)
{
	try
	{
		(void)dynamic_cast<A &>(base);
		std::cout << "A" << std::endl;
	}
	catch (std::exception) {}
	try
	{
		(void)dynamic_cast<B &>(base);
		std::cout << "B" << std::endl;
	}
	catch (std::exception) {}
	try
	{
		(void)dynamic_cast<C &>(base);
		std::cout << "C" << std::endl;
	}
	catch (std::exception) {}
}

int main(void)
{
	srand(time(NULL));
	Base *base[10];
	for (int i = 0; i < 10; i++)
		base[i] = generate();
	std::cout << "identify with pointer" << std::endl;
	for (int i = 0; i < 10; i++)
		identify(base[i]);
	std::cout << "identify with reference" << std::endl;
	for (int i = 0; i < 10; i++)
		identify(*base[i]);
}
