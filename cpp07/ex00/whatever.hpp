/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:48:35 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/06 15:56:50 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

/*Swaps values of passed arguments*/
template<class T>
void swap(T& a, T& b) {
	T c;
	c = a;
	a = b;
	b = c;
}

/*Returns a in case it is smaller than b, otherwise returns b*/
template<class T>
T min(T a, T b) {
	return (a < b ? a : b);
}

/*Returns a in case it is bigger than b, otherwise returns b*/
template<class T>
T max(T a, T b) {
	return (a > b ? a : b);
}

#endif