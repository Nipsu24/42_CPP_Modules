/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:33:25 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/19 17:46:17 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : mVecArr(other.mVecArr), mDeqArr(other.mDeqArr),
			mNumberPairs(other.mNumberPairs), mVecArrLarge(other.mVecArrLarge), mVecArrSmall(other.mVecArrSmall) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other)
		return (*this);
	mVecArr = other.mVecArr;
	mDeqArr = other.mDeqArr;
	mNumberPairs = other.mNumberPairs;
	mVecArrLarge = other.mVecArrLarge;
	mVecArrSmall = other.mVecArrSmall;
	return (*this);
}

PmergeMe::~PmergeMe() {}

std::ostream& operator<<(std::ostream& os, std::vector<int>& printVec) {
	for (size_t i = 0; i < printVec.size(); ++i) {
		os << printVec[i];
		if (i != printVec.size() - 1)
			os << ",";
	}
    return (os);
}

/*Checks if input sequence contains anything else than numbers. If only numbers present,
  stores content in vector and deque array of ints.*/
bool PmergeMe::checkValidInput(std::vector<std::string>& input) {
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

/*Creates number pairs and stores them into vector of vector of ints. Then compares the values within
  each pair and stores them into a vector array consisting of the larger numbers of each pair and a 
  vector consisting of the small numbers of each pair.*/
void	PmergeMe::splitInitiallyIntoPairsVector() {
	int amountOfPairVectors = 0;
	if (mVecArr.size() % 2 == 0)
	 	amountOfPairVectors = mVecArr.size() / 2;
	else
		amountOfPairVectors = ((mVecArr.size() - 1) / 2) + 1;
	mNumberPairs.resize(amountOfPairVectors);
	size_t i = 0;
	int j = 0;
	for (int member : mVecArr) {
		if (i != 0 && i % 2 == 0)
			j++;
		mNumberPairs[j].push_back(member);
		i++;
	}
	for (const std::vector<int>& member : mNumberPairs) {
		if (member.size() == 2) {
			if (member[0] <= member[1]) {
				mVecArrLarge.push_back(member[1]);
				mVecArrSmall.push_back(member[0]);
			}
			else {
				mVecArrLarge.push_back(member[0]);
				mVecArrSmall.push_back(member[1]);
			}
		} 
		else if (member.size() == 1)
			mVecArrLarge.push_back(member[0]);
	}
}

void	PmergeMe::mergeSortVector()	{
	splitInitiallyIntoPairsVector();
	std::cout << "Vector Pairs:" << std::endl;
	for (std::vector<int> member : mNumberPairs) {
		std::cout << member << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Large Numbers:" << std::endl;
	for (int member : mVecArrLarge) {
		std::cout << member << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Small Numbers:" << std::endl;
	for (int member : mVecArrSmall) {
		std::cout << member << std::endl;
	}
}

// void	PmergeMe::mergeSortDeque()	{
	
// }
