/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/10 14:13:52 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main( void ) {
	try {
		std::cout << "Pass int 4 to array from 1 to 6:" << std::endl;
		std::vector<int> intArray = {1, 2, 3, 4, 5, 6};
		::easyfind(intArray, 4);
		std::cout << "Integer appears in array." << std::endl;

		std::cout << "Pass int 7 to array from 1 to 6:" << std::endl;
		::easyfind(intArray, 7);
		std::cout << "Integer appears in array." << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
