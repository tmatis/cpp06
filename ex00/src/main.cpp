/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 21:51:36 by tmatis            #+#    #+#             */
/*   Updated: 2021/08/25 22:02:18 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Scalar n(argv[1]);

		std::cout << n;
	}
	else
		std::cout << "Usage: ./Scalar <number>" << std::endl;
}
