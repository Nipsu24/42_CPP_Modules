/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:04:29 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/13 17:30:54 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { (void)other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this == &other)
		return (*this);
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::calculateBitcoinExchangeRate(const std::string inputFile) {
	std::cout << "Input File is: " << inputFile << std::endl;
}
