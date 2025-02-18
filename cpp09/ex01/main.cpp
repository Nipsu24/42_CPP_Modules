/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:43:32 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/18 16:02:27 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

/*Checks for insufficient arguments passed to function, converts argument into string and
  passes it to member functions for further processing.*/
int main(int ac, char* av[]) {
	if (ac != 2) {
		std::cerr << "Error. Insufficient arguments passed to program." << std::endl;
		return (1);
	}
	std::string input = av[1];
	RPN calculator;
	if (!calculator.checkForValidInput(input)) {
		return (1);
	}
	calculator.calculateResult();
	return (0);
}