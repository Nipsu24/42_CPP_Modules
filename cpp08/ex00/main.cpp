/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/10 15:05:27 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main( void ) {
	try {
		std::cout << "Pass int 4 to int array from 1 to 6:" << std::endl;
		std::vector<int> intArray = {1, 2, 3, 4, 5, 6};
		::easyfind(intArray, 4);
		std::cout << "Integer appears in array." << std::endl;
		
		std::cout << "Pass int 4 to double array from 1.0 to 6.0:" << std::endl;
		std::vector<double> doubleArray = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
		::easyfind(doubleArray, 4);
		std::cout << "Integer appears in array." << std::endl;

		std::cout << "Pass int 7 to int array from 1 to 6:" << std::endl;
		::easyfind(intArray, 7);
		std::cout << "Integer appears in array." << std::endl;

	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
