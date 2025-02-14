/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:04:29 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/14 16:10:56 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { (void)other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this == &other)
		return (*this);
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::calculateBitcoinExchangeRate(const std::string inputFile) {
	std::ifstream	bitCoinData;
	
	bitCoinData.open("data.csv");
	if (!bitCoinData.is_open()) {
		std::cerr << "Error. Bitcoin data file could not be opened" << std::endl;
		return ;
	}
	std::string	fileContent;
	while (std::getline(bitCoinData, fileContent)) {
		std::istringstream	iss(fileContent);
		std::string			date;
		double				rate;
		if (std::getline(iss, date, ',') && iss >> rate)
			mMap[date] = rate;
	}
	bitCoinData.close();
}
