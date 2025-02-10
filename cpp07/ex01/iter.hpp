/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:48:35 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/10 11:43:23 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void printArr(T& value) {
    std::cout << value << std::endl;
}

/*typename or class can be used interchangeably*/
template<typename T>
void increment(T& value) {
    value++;
}

/*Defines typenames for each argument*/
template<typename T, typename len, typename func> 
void iter( T* array, len length, func *f) {
	if (array == nullptr) {
		std::cout << "Error. Nullptr passed to function." << std::endl;
		return ;
	}
	for (len i = 0; i < length; i++)
		f(array[i]);
}

#endif