/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:48:35 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/07 16:48:05 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <array>
#include <iostream>

/*typename or class can be used interchangeably*/
template<typename T>
void increment(T& value) {
    value++;
}

template<typename T>
void print(T& value) {
    std::cout << value << std::endl;
}

template<typename T>
void iter(T* array, std::size_t length, void (*func)(T&)) {
	for (std::size_t i = 0; i < length; i++)
		func(array[i]);
}


#endif