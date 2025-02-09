/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/09 14:09:01 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main( void ) {
	try {
		std::cout << "Construct empty array" << std::endl;
		Array<int> emptyArray;
		std::cout << "Size of empty array: " << emptyArray.size() << std::endl;
		std::cout << std::endl;
		
		std::cout << "Construct array with 5 members" << std::endl;
		Array<int> membersArray(5);
		std::cout << "Size of array: " << membersArray.size() << std::endl;
		std::cout << std::endl;
		
		std::cout << "Copy array with 5 members" << std::endl;
		Array<int> copyArray(membersArray);
		std::cout << "Size of copy array: " << copyArray.size() << std::endl;
		std::cout << std::endl;
		
		copyArray[1] = 10;
		std::cout << "Value of copy array on Index 1: " << copyArray[1] << std::endl;
		std::cout << "Value of initial array on Index 1: " << membersArray[1] << std::endl;
		std::cout << std::endl;
		
		std::cout << "Copy assignment to another array" << std::endl;
		Array<int> anotherCopyArray = copyArray;
		std::cout << "Value of assigned copy array on Index 1 before change: " << anotherCopyArray[1] << std::endl;
		anotherCopyArray[1] = 20;
		std::cout << "Value of assigned copy array on Index 1 after change: " << anotherCopyArray[1] << std::endl;
		std::cout << "Value of copy array on Index 1 after change: " << copyArray[1] << std::endl;
		
		std::cout << std::endl;
		std::cout << "Initialise string array with 3 members" << std::endl;
		Array<std::string> stringArray(3);
		stringArray[0] = "Hello";
		stringArray[1] = "World";
		stringArray[2] = "!";
		std::cout << "Content of string array:" << std::endl;
		for (size_t i = 0; i < 3; i++)
			std::cout << stringArray[i] << std::endl;
		std::cout << std::endl;
		
		std::cout << "Try access non-existent index 3" << std::endl;
		std::cout << "Content string array at index 3: " << stringArray[3] << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
