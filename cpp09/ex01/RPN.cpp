/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:40 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/19 09:18:21 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN& other) : mList(other.mList), mStack(other.mStack) {}

RPN& RPN::operator=(const RPN& other) {
	if (this == &other)
		return (*this);
	mList = other.mList;
	mStack = other.mStack;
	return (*this);
}

RPN::~RPN() {}

/*Checks for empty input string. Then uses istringstream to write each word of input string
  into token string, where it is directly assessed whether it is a number (operant) or one
  of the valid operators. Counts occurence of numbers and operators, as RPN requires one
  operator less than amount of operants in equation statement. Saves token in list array
  for further processing in calculateResult method.*/
bool	RPN::checkForValidInput(const std::string& input) {
	if (input.empty()) {
		std::cerr << "Error. Empty argument passed to program." << std::endl;
		return (false);
	}
	std::istringstream	iss(input);
	std::string 		token;
	int					numberCount = 0;
	int					signCount = 0;
	while (iss >> token)
	{
		if (std::all_of(token.begin(), token.end(), ::isdigit)) {
			mList.push_back(token);
			numberCount++;
		}
		else {
			if (token == "+" || token == "-" || token == "*" || token == "/")
				signCount++;
			else {
				std::cerr << "Error. Argument contains invalid characters." << std::endl;
				return (false);
			}
			mList.push_back(token);
		}
	}
	if (numberCount - 1 != signCount) {
		std::cerr << "Error. Argument does not contain sufficient amount of operants / operators for RPN." << std::endl;
		return (false);
	}
	return (true);
}

/*Iterates through list array and converts strings consisting out of digits (checked in checkForValidInput method)
  into ints. Then pushes number to stack. If operator is encountered, assigns first and second top value of stack
  to iterators and pops the values out of the stack respectively. Then conducts mathematical operation with the 2
  numbers depending on the operator sign and pushes result back to stack. Prints out final result when end of list
  reached. Final error check only for safety, could not reproduce any case which has not been caught previously.*/
void	RPN::calculateResult() {
	int	number = 0;
	int result = 0;
	for (auto it = mList.begin(); it != mList.end(); it++) {
		if (std::isdigit((*it)[0])) {
			try {
				number = stoi(*it);
				mStack.push(number);
			}
			catch (std::out_of_range &e) {
				std::cerr << "Error. Argument contains one or more too large numbers." << std::endl;
				return;
			}
		}
		else {
			if (mStack.size() < 2) {
				std::cerr << "Error. Operants / operators incorrectly placed." << std::endl;
				return;
			}
			auto	secondOperant = mStack.top();
				mStack.pop();
			auto	firstOperant = mStack.top();
				mStack.pop();
			if (*it == "+") {
				result = firstOperant + secondOperant;
				mStack.push(result);
			}
			else if (*it == "-") {
				result = firstOperant - secondOperant;
				mStack.push(result);
			}
			else if (*it == "*") {
				result = firstOperant * secondOperant;
				mStack.push(result);
			}
			else if (*it == "/") {
				result = firstOperant / secondOperant;
				mStack.push(result);
			}
		}
	}
	if (mStack.size() != 1) {
		std::cerr << "Error. Stack still has extra values after final calculation." << std::endl;
		return;
	}
	std::cout << result << std::endl;
}
