/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/06 15:41:36 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int	main(void) {
	int a = 5;
	int b = 10;
	
	std::cout << "Before swap" << std::endl;
	std::cout << "a is: " << a << std::endl;
	std::cout << "b is: " << b << std::endl;
	swap(a, b);
	std::cout << "After swap" << std::endl;
	std::cout << "a is: " << a << std::endl;
	std::cout << "b is: " << b << std::endl;
	
	int c = min(a, b);
	std::cout << "Min value is: " << c << std::endl;
	c = max(a, b);
	std::cout << "Max value is: " << c << std::endl;
	
	return (0);
}


// int main( void ) {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }
