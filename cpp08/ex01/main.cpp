/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/11 15:00:55 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>

int main(void) {
	try {
		std::cout << "Initialise array with 5 elements" << std::endl;
		Span firstArray(5);
		for (int i = 0; i < 5; i++) {
			firstArray.addNumber(i);
			std::cout << i << std::endl;
		}
		std::cout << "Add 6th element to array" << std::endl;
		firstArray.addNumber(6);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "Initialise array with 0 or negative elements" << std::endl;
		Span secondArray(-1);
		secondArray.addNumber(-6);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	try {
		std::cout << "Initialise array with following values: -20, 1, 10, 8" << std::endl;
		Span thirdArray(4);
		thirdArray.addNumber(-20);
		thirdArray.addNumber(1);
		thirdArray.addNumber(10);
		thirdArray.addNumber(8);
		
		int shortest = thirdArray.shortestSpan();
		int longest = thirdArray.longestSpan();
		std::cout << "Shortest Span is: " << shortest << std::endl;
		std::cout << "Longest Span is: " << longest << std::endl;
		
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Initialise array with 200 numbers from 200-399" << std::endl;
		Span fourthArray(200);
		fourthArray.addSpan(200, 399);
		int shortest = fourthArray.shortestSpan();
		int longest = fourthArray.longestSpan();
		std::cout << "Shortest Span is: " << shortest << std::endl;
		std::cout << "Longest Span is: " << longest << std::endl;
		std::cout << "Add further elements to array " << std::endl;
		fourthArray.addSpan(100, 120);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Initialise array with 10001 numbers from 0-10000" << std::endl;
		Span fivthArray(10001);
		fivthArray.addSpan(0, 10000);
		int shortest = fivthArray.shortestSpan();
		int longest = fivthArray.longestSpan();
		std::cout << "Shortest Span is: " << shortest << std::endl;
		std::cout << "Longest Span is: " << longest << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }