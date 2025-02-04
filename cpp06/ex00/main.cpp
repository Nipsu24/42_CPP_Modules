/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/04 16:51:30 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(void) {
	
	std::cout << "a" << std::endl;
	ScalarConverter::convert("a");
	std::cout << std::endl;
	
	std::cout << "10.0f" << std::endl;
	ScalarConverter::convert("10.0f");
	std::cout << std::endl;
	
	std::cout << "42.0f" << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;
	
	std::cout << "10" << std::endl;
	ScalarConverter::convert("10");
	std::cout << std::endl;
	
	std::cout << "2147483648" << std::endl;
	ScalarConverter::convert("2147483648");
	std::cout << std::endl;
	
	std::cout << "-2147483649" << std::endl;
	ScalarConverter::convert("-2147483649");
	std::cout << std::endl;
	
	std::cout << "nan" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;

	std::cout << "--10" << std::endl;
	ScalarConverter::convert("--10");
	std::cout << std::endl;

	std::cout << "-inf" << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << std::endl;

	std::cout << "+inff" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << std::endl;
	
	
}
