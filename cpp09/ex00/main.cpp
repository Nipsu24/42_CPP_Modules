/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:13:01 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/18 10:23:37 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

/*First checks if sufficient amount of arguments are passed to program. Then converts
  input file into std::string and builts BitcoinExchange class object. Afterwards passes
  string input file to member function for further processing.*/
int	main(int ac, char* av[]) {
	if (ac != 2) {
		std::cerr << "Error. Insufficient arguments passed to program" << std::endl;
		return (1);
	}
	std::string inputFile = av[1];
	BitcoinExchange bitcoin;
	bitcoin.calculateBitcoinExchangeRate(inputFile);
	return (0);
}
