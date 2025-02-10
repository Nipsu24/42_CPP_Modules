/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/10 11:43:29 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

/*Uses division between total size of intArray and sizeof single member of array
  in order to retrieve number of members in the array.*/
int main( void ) {
	std::cout << "Initialise int array with 3 members" << std::endl;
	std::cout << "Values before passing to iter/increment function:" << std::endl;
	int intArray[] = {5, 10, 15};
	for (int i = 0; i < 3; i++) {
		std::cout << intArray[i] << std::endl;
	}
	::iter(intArray, sizeof(intArray) / sizeof(intArray[0]), increment<int>);
	std::cout << "Values after passing to iter/increment function:" << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << intArray[i] << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Initialise string array with 3 members " << std::endl;
	std::string strArray[] = {"Hello", "World", "!"};
	::iter(strArray, sizeof(strArray) / sizeof(strArray[0]), printArr<std::string>);
	std::cout << std::endl;
	
	std::cout << "Passing empty int array (nullptr) to iter function" << std::endl;
	int* nullptrIntArray = nullptr;
	::iter(nullptrIntArray, 0, increment<int>);
	return (0);
}
