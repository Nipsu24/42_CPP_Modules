/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/09 13:34:38 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) + Fixed(2));
	Fixed const c(Fixed(5.05f) - Fixed(2));
	Fixed const d(Fixed(5.05f) * Fixed(2));
	Fixed const e(Fixed(5.05f) / Fixed(2));
	Fixed const	f(Fixed(5.05f) + Fixed(2));
	Fixed const	g(Fixed(5.05f) - Fixed(2));
	Fixed		h(Fixed(5.0f) + Fixed(2));
	Fixed		i(Fixed(5.0f) + Fixed(2));

	std::cout << "a is: " << a << std::endl;
	std::cout << "b is: " << b << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "d is: " << d << std::endl;
	std::cout << "e is: " << e << std::endl;
	std::cout << "f is: " << f << std::endl;
	std::cout << "g is: " << g << std::endl;
	std::cout << std::endl;
	if (b > c)
		std::cout << "b is bigger than c" << std::endl;
	if (c < b)
		std::cout << "c is smaller than b" << std::endl;
	if (b <=f)
		std::cout << "b is equal/smaller to f" << std::endl;
	if (b >=f)
		std::cout << "b is equal/bigger to f" << std::endl;
	if (b==f)
		std::cout << "b is equal to f" << std::endl;
	if (a != b)
		std::cout << "a is not equal to b" << std::endl;
	std::cout << std::endl;
	std::cout << "Comparing a and b, b has max value. The value is: "<< Fixed::max(a, b) << std::endl;
	std::cout << "Comparing a and g, g has max value. The value is: "<< Fixed::max(a, g) << std::endl;
	std::cout << "Comparing c and d, c has min value. The value is: "<< Fixed::min(c, d) << std::endl;
	std::cout << "Comparing a and g, a has min value. The value is: "<< Fixed::min(a, g) << std::endl;
	
	std::cout << "h before postincrement " << h << std::endl;
	h++;
	std::cout << "h after postincrement " << h << std::endl;
	std::cout << "i before preincrement " << i << std::endl;
	++i;
	std::cout << "i after preincrement " << i << std::endl;
	std::cout << "h before postdecrement " << h << std::endl;
	h--;
	std::cout << "h after postdecrement " << h << std::endl;
	std::cout << "i before predecrement " << i << std::endl;
	--i;
	std::cout << "i after predecrement " << i << std::endl;
	std::cout << std::endl;
	a = --i;
	std::cout << "a = --i, a is " << a << std::endl;
	a = i++;
	std::cout << "a = i++, a is " << a << std::endl;
	a = i--;
	std::cout << "a = i--, a is " << a << std::endl;
	a = ++i;
	std::cout << "a = ++i, a is " << a << std::endl;
	return (0);
}