/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/07 16:50:55 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <array>

/*Uses division between total size of intArray and sizeof single member of array
  in order to retrieve number of members in the array.*/
int main( void ) {
	int intArray[] = {5, 10, 15};
	::iter(intArray, sizeof(intArray) / sizeof(intArray[0]), increment<int>);
	for (int i = 0; i < 3; i++) {
		std::cout << intArray[i] << std::endl;
	}
	std::string strArray[] = {"Hello", "World", "!"};
	::iter(strArray, sizeof(strArray) / sizeof(strArray[0]), print<std::string>);
	return (0);
}
