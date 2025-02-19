/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:33:25 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/19 11:04:18 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <iostream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : mVecArr(other.mVecArr), mDeqArr(other.mDeqArr) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other)
		return (*this);
	mVecArr = other.mVecArr;
	mDeqArr = other.mDeqArr;
	return (*this);
}

PmergeMe::~PmergeMe() {}

/*Checks if input sequence contains anything else than numbers. If only numbers present,
  stores content in vector and deque array of ints.*/
bool PmergeMe::checkValidInput(std::vector<std::string> input) {
	for (std::string member : input) {
		if (!std::all_of(member.begin(), member.end(), ::isdigit)) {
			std::cerr << "Error. Sequence contains not allowed characters." << std::endl;
			return (false);
		}
	}
	for (std::string member : input) {
		try {
			mVecArr.push_back(stoi(member));
		}
		catch (std::out_of_range &e) {
			std::cerr << "Error. Sequence contains numbers which are out of range." << std::endl;
			return (false);
		}
	}
	for (int member : mVecArr)
		mDeqArr.push_back(member);
	return (true);
}
