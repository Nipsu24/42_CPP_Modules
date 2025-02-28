/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:04:29 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/28 10:39:56 by mmeier           ###   ########.fr       */
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

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : mMap(other.mMap) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this == &other)
		return (*this);
	mMap = other.mMap;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

/*Takes substr. of inputBuffer to extract date section and bitcoin amount section. 
  Uses stof to convert bitcoin amount into float. Applies iteration logic through map array
  in order to find matching date/closest matching date which is still lower than the date passed
  from the test file. If it->first is > closestIt, it means it->first is closer to the given date
  than closestIt->first. In case no date is found (if for instance a date is passsed that predates
  any value stored in the map) a respective error text is printed. Else, a text is printed, which
  multiplies the bitcoin amount with the value of bitcoin at given date (closestIt->second).*/
void	BitcoinExchange::compareDataWithInput(const std::string inputBuffer) {
	std::string	date;
	std::string bitcoinAmountStr;
	date = inputBuffer.substr(0, 10);
	bitcoinAmountStr = inputBuffer.substr(13);
	float	bitcoinAmount = stof(bitcoinAmountStr);
	std::map<std::string, float>::iterator closestIt = mMap.end();
	for (auto it = mMap.begin(); it != mMap.end(); it++) {
		if (it->first <= date) {
			if (closestIt == mMap.end() || it->first > closestIt->first) {
                closestIt = it;
            }
		}
	}
	if (closestIt == mMap.end())
		std::cout << "Error. No date matches given input (given date predates any available dates)." << " => " << date << std::endl;
	else
		std::cout << closestIt->first << " => " << bitcoinAmount << " = " << bitcoinAmount * closestIt->second << std::endl;
}

/*Converts number part of inputBuffer into float and checks whether the number is in the
  requested range of 0-1000. Also handles potential overflow with try/catch.*/
bool BitcoinExchange::validateNumberContent(std::string& inputBuffer) {
	std::string number = inputBuffer.substr(13);
	try {
		float bitcoinAmount = stof(number);
		if (bitcoinAmount > 1000 || bitcoinAmount < 0) {
			std::cout << "Error. Number out of range => " << number << std::endl;
			return (false);
		}
	}
	catch (std::out_of_range &e){
			std::cout << "Error. Number too high (out of range)." << std::endl;
			return (false);
	}
	return (true);
}

/*Checks whether month is in valid range and conducts further checks for day range (31 vs. 30 days/month).
  Dedicated check for leap year with modulo calculation for February.*/
bool BitcoinExchange::validateDateContent(std::string& inputBuffer) {
	std::string yearStr = inputBuffer.substr(0, 4);
	std::string monthStr = inputBuffer.substr(5, 2);
	std::string dayStr = inputBuffer.substr(8, 2);

	int year = stoi(yearStr);
	int month = stoi(monthStr);
	int day = stoi(dayStr);

	if (month < 1 || month > 12) {
			std::cerr << "Error. Bad input (month) => " << inputBuffer << std::endl;
			return (false);
	}
	if (month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12) {
		if (day < 1 || day > 31) {
			std::cerr << "Error. Bad input (day) => " << inputBuffer << std::endl;
			return (false);
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day < 1 || day > 30) {
			std::cerr << "Error. Bad input (day) => " << inputBuffer << std::endl;
			return (false);
		}
	}
	else if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			if (day < 1 || day > 29) {
				std::cerr << "Error. Bad input (day) => " << inputBuffer << std::endl;
				return (false);	
			}
		}
		else if (day < 1 || day > 28) {
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
  Handles additionally cases where line (inputBuffer) only contains whitespaces.*/
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
  and prints respective error text. Explanation of regex notation: s: space; d+: arbitrary amount of digits;
  ?: optional values (in this case '-' sign and digits after '.' )*/
bool	BitcoinExchange::validateSeparatorAndNumberFormat(std::string& inputBuffer) {
	std::regex	separatorRegex(R"(\s\|\s)");
	std::regex	numberRegex(R"(-?\d+(\.\d+)?)");
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

/*Reads data from .csv file and strores it by using getline and iss into map array. Values
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

/*Checks if passed file is a valid file (and not e.g. a directory). Then reads first line of test file
  passed to program in order to handle the header properly. Stores values of .csv file in map array.
  Then reads content of file line by line and checks each line for valid format and content. Ultimately
  compares content of file with stored map values in compareDataWithInput function.*/
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
	std::string headerInput;
	std::getline(input, headerInput);
	std::string	inputBuffer;
	storeBitcoinDataInMap();
	while (getline(input, inputBuffer)) {
		if (validateInputFormat(inputBuffer)) {
			if (validateInputContent(inputBuffer)) {
				compareDataWithInput(inputBuffer);
			}
		}
	}
	input.close();	
}
