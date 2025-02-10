/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/10 17:02:09 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
// #include <exception>

int main( void ) {
	
	try {
		Span firstArray(5);
		for (int i = 0; i < 5; i++) {
			firstArray.addNumber(i);
			std::cout << i << std::endl;
		}
		firstArray.addNumber(6);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Span secondArray(0);
		secondArray.addNumber(-6);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	try {
		Span thirdArray(4);
		thirdArray.addNumber(5);
		thirdArray.addNumber(1);
		thirdArray.addNumber(10);
		thirdArray.addNumber(8);
		
		std::cout << "Shortest Span is: " << thirdArray.shortestSpan() << std::endl;
		
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
