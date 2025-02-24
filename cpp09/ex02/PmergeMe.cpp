/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:33:25 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/24 11:44:29 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

PmergeMe::PmergeMe() : mRecursionLevel(1) {}

PmergeMe::PmergeMe(const PmergeMe& other) : mVecArr(other.mVecArr), mDeqArr(other.mDeqArr),
			mNumberPairs(other.mNumberPairs), mRecursionLevel(other.mRecursionLevel) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other)
		return (*this);
	mVecArr = other.mVecArr;
	mDeqArr = other.mDeqArr;
	mNumberPairs = other.mNumberPairs;
	mRecursionLevel = other.mRecursionLevel;
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

/*Creates number pairs and stores them into vector of vector of ints (mNumberPairs). Then compares the
  values within each pair and swaps them if required so that larger int is always on index [1].*/
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
	for (std::vector<int>& member : mNumberPairs) {
		if (member.size() == 2) {
			if (member[0] > member[1])
				std::swap(member[0], member[1]);
		}
	}
}

void	PmergeMe::sortRecursively(std::vector<std::vector<int>> input) {
	mRecursionLevel++;
	if (input.size() < 2)
		return ;
	size_t i = 0;
	int j = 0;
	int amountElementPerGroup = 1 << mRecursionLevel; // bitshift for power of .e.g. 2^2
	int amountOfGroups = input.size() / 2;
	std::vector<std::vector<int>> nextLevelInput;
	nextLevelInput.resize(amountOfGroups);
	for (auto& member : input) {
		for (int num : member) {
			if (j < amountOfGroups)
				nextLevelInput[j].push_back(num);
			i++;
			if (i % amountElementPerGroup == 0) {
				j++;
			if (j >= amountOfGroups)
				break ;
			}
		}
	}
	for (auto& group : nextLevelInput) {
		if (group.size() >= 2) {
			int middleIndex = group.size() / 2;
			// Compare last element with the middle element
			if (group.back() < group[middleIndex - 1]) {
				// Swap the two subgroups (first half with second half)
				std::vector<int> firstHalf(group.begin(), group.begin() + middleIndex);
				std::vector<int> secondHalf(group.begin() + middleIndex, group.end());
				std::copy(secondHalf.begin(), secondHalf.end(), group.begin());
				std::copy(firstHalf.begin(), firstHalf.end(), group.begin() + middleIndex);
			}
		}
	}
	//debug printing
	std::cout << "members in " << mRecursionLevel << ". recursion" << std::endl;
	for (auto& member : nextLevelInput)
		std::cout << member << std::endl;
	sortRecursively(nextLevelInput);
}

void	PmergeMe::mergeSortVector()	{
	splitInitiallyIntoPairsVector();
	sortRecursively(mNumberPairs);
}
