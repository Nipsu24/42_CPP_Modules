/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:48:35 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/10 14:58:32 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T>
void easyfind(T& paraA, int paraB) {
	if (std::find(paraA.begin(), paraA.end(), paraB) != paraA.end())
		return; 
	else
		throw std::runtime_error("Value could not be found in array.");
}

#endif