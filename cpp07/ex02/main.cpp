/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/08 18:09:15 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main( void ) {
	Array<int> emptyArray;
	std::cout << "Size of empty array: " << emptyArray.size() << std::endl;
	std::cout << std::endl;
	Array<int> membersArray(5);
	std::cout << "Size of array: " << membersArray.size() << std::endl;
	return (0);
}
