/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:04:29 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/17 15:22:16 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <filesystem>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { (void)other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this == &other)
		return (*this);
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

// void	BitcoinExchange::compareDataWithInput(const std::string inputFile) {
	// storeBitcoinDataInMap();
// }

/*Converts number part of inputBuffer into float and checks whether the number is in the
  requested range of 0-1000. Also handles potential overflow with try/catch.*/
bool BitcoinExchange::validateNumberContent(std::string& inputBuffer) {
	std::string number = inputBuffer.substr(13);
	try {
		float bitcoinAmount = stof(number);
		if (bitcoinAmount > 1000 || bitcoinAmount < 0) {
			std::cout << "Error. Number too high (out of range)." << std::endl;
			return (false);
		}
	}
	catch (std::out_of_range &e){
			std::cout << "Error. Number too high (out of range)." << std::endl;
			return (false);
	}
	return (true);
}

/*Checks whether month is in valid range and conducts further checks for day range (31 vs 30 days month).
  Dedicated check for leap year with modulo calculation for february.*/
bool BitcoinExchange::validateDateContent(std::string& inputBuffer) {
	std::string yearStr = inputBuffer.substr(0, 4);
	std::string monthStr = inputBuffer.substr(5, 2);
	std::string dayStr = inputBuffer.substr(8, 2);

	int year = stoi(yearStr);
	int month = stoi(monthStr);
	int day = stoi(dayStr);

	if (month < 1 || month > 12) {
			std::cerr << "Error. Bad input (month) =>" << inputBuffer << std::endl;
			return (false);
	}
	if (month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12) {
		if (day < 0 || day > 31) {
			std::cerr << "Error. Bad input (day) => " << inputBuffer << std::endl;
			return (false);
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day < 0 || day > 30) {
			std::cerr << "Error. Bad input (day) => " << inputBuffer << std::endl;
			return (false);
		}
	}
	else if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			if (day < 0 || day > 29) {
				std::cerr << "Error. Bad input (day) => " << inputBuffer << std::endl;
				return (false);	
			}
		}
		else if (day < 0 || day > 28) {
			std::cerr << "Error. Bad input (day) => " << inputBuffer << std::endl;
			return (false);	
		}
	}
	return (true);
}

/*Checks for valid content of input*/
bool	BitcoinExchange::validateInputContent(std::string& inputBuffer) {
	if (!validateDateContent(inputBuffer) || !validateNumberContent(inputBuffer))
		return (false);
	return (true);
}

/*Uses regex to define accepted date format and checks if the date sequence of the inputBuffer
  follow this format. Returns false if it is not the case and prints respective error text.
  Hanldes additionally case where line (inputBuffer) only contains whitespaces.*/
bool	BitcoinExchange::validateDateFormat(std::string& inputBuffer) {
	std::regex	dateRegex(R"(\d{4}-\d{2}-\d{2})");
	if (inputBuffer.size() >= 10) {
		std::string date = inputBuffer.substr(0, 10);
		if (!std::regex_match(date, dateRegex)) {
			std::cerr << "Error. Bad input (date format) => " << date << std::endl;
			return (false);
		}
	}
	else {
		if (inputBuffer.empty() || std::all_of(inputBuffer.begin(), inputBuffer.end(), ::isspace)) {
			std::cerr << "Error. Input only contains whitespace." << std::endl;
			return (false);
		}
		else {
			std::cerr << "Error. Line too short to contain a valid date => " << inputBuffer << std::endl;
			return (false);
		}
	}
	return (true);
}

/*Uses regex to define accepted separator and number format and checks if the sequence of the inputBuffer
  where the seperator and the number are expected follow this format. Returns false if it is not the case 
  and prints respective error text.*/
bool	BitcoinExchange::validateSeparatorAndNumberFormat(std::string& inputBuffer) {
	std::regex	separatorRegex(R"(\s\|\s)");
	std::regex	numberRegex(R"(-?\d+(\.\d{1,3})?)");
	if (inputBuffer.size() >= 12) {
		std::string separator = inputBuffer.substr(10, 3);
		if (!std::regex_match(separator, separatorRegex)) {
			std::cerr << "Error. Bad input (separator) => " << inputBuffer << std::endl;
			return (false);
		}
		else {
			std::string number = inputBuffer.substr(13);
			if (!std::regex_match(number, numberRegex)) {
				std::cerr << "Error. Invalid number format => " << inputBuffer << std::endl;
				return (false); 
			}
		}
	}
	else {
		std::cerr << "Invalid separator format => " << inputBuffer << std::endl;
		return (false);
	}
	return (true);
}

/*Checks if date, separator and number have the correct format and returns true if this is the case.*/
bool	BitcoinExchange::validateInputFormat(std::string& inputBuffer) {
	if (!validateDateFormat(inputBuffer) || !validateSeparatorAndNumberFormat(inputBuffer))
		return (false);
	return (true);
}

/*Reads data from .csv file and strores it by using getline and iss into map array. Valules
  in map are separated by ','.*/
void	BitcoinExchange::storeBitcoinDataInMap() {
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
		float				rate;
		if (std::getline(iss, date, ',') && iss >> rate)
			mMap[date] = rate;
	}
	bitCoinData.close();
}

/*Checks if passed file is a valid file (and not e.g. a directory). Then reads first line of testfile
  passed to program in order to handle the header properly. Then reads content of file line by line and
  checks each line for valid format and content. Ultimately compares content of file with stores map values
  in compareDataWithInput function.*/
void	BitcoinExchange::calculateBitcoinExchangeRate(const std::string inputFile) {
	if (!std::filesystem::is_regular_file(inputFile)) {
		std::cerr << "Error. The provided path is not a regular file." << std::endl;
		return;
	}
	std::ifstream	input;
	input.open(inputFile);
	if (!input.is_open()) {
		std::cerr << "Error. Input file could not be opened" << std::endl;
		return ;
	}
	//handles header in inputFile
	std::string headerInput;
	std::getline(input, headerInput);
	
	std::string	inputBuffer;
	while (getline(input, inputBuffer)) {
		if (validateInputFormat(inputBuffer)) {
			std::cout << "IS VALID FORMAT" << std::endl;
			if (validateInputContent(inputBuffer)) {
				std::cout << "IS VALID INPUT" << std::endl;
				// compareDataWithInput(inputFile);
			}
		}
	}
	input.close();
	
}
