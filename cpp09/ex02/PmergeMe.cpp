/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:33:25 by mmeier            #+#    #+#             */
/*   Updated: 2025/03/02 13:05:05 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iterator>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : mVecArr(other.mVecArr), mVecArrLarge(other.mVecArrLarge), mVecArrSmall(other.mVecArrSmall),
											mDeqArr(other.mDeqArr), mDeqArrLarge(other.mDeqArrLarge), mDeqArrSmall(other.mDeqArrSmall) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other)
		return (*this);
	mVecArr = other.mVecArr;
	mVecArrSmall = other.mVecArrSmall;
	mVecArrLarge = other.mVecArrLarge;
	mDeqArr = other.mDeqArr;
	mDeqArrSmall = other.mDeqArrSmall;
	mDeqArrLarge = other.mDeqArrLarge;
	return (*this);
}

PmergeMe::~PmergeMe() {}

/*getter Vector size*/
size_t	PmergeMe::getVectorSize() { return (mVecArr.size()); }

/*Deque implementation of above function*/
size_t	PmergeMe::getDequeSize() { return (mDeqArr.size()); }

/*Checks if input sequence contains anything else than numbers. If only numbers present,
  stores content in vector and deque array of ints.*/
bool PmergeMe::checkValidInputVector(std::vector<std::string>& input) {
	for (std::string member : input) {
		if (!std::all_of(member.begin(), member.end(), ::isdigit) || member.empty()) {
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
	return (true);
}

/*Deque implementation of above function*/
bool PmergeMe::checkValidInputDeque(std::deque<std::string>& input) {
	for (std::string member : input) {
		if (!std::all_of(member.begin(), member.end(), ::isdigit)) {
			std::cerr << "Error. Sequence contains not allowed characters." << std::endl;
			return (false);
		}
	}
	for (std::string member : input) {
		try {
			mDeqArr.push_back(stoi(member));
		}
		catch (std::out_of_range &e) {
			std::cerr << "Error. Sequence contains numbers which are out of range." << std::endl;
			return (false);
		}
	}
	return (true);
}

/*Iterates through pairs of numbers and stores them depending on their size into two separate vectors
  - small and large. In case there is an odd amount of elements in the vector, stores the remaining
  element without a pair into the small numbers vector.*/
void	PmergeMe::splitIntoSmallAndLargeVec() {
	for (size_t i = 1; i < mVecArr.size(); i += 2) {
		if (mVecArr[i - 1] > mVecArr[i]) {
			mVecArrSmall.push_back(mVecArr[i]);
			mVecArrLarge.push_back(mVecArr[i - 1]);
		}
		else {
			mVecArrSmall.push_back(mVecArr[i - 1]);
			mVecArrLarge.push_back(mVecArr[i]);
		}
	}
	if (mVecArr.size() % 2 != 0)
		mVecArrSmall.push_back(mVecArr.back());
}

/*Deque implementation of above function*/
void	PmergeMe::splitIntoSmallAndLargeDeq() {
	for (size_t i = 1; i < mDeqArr.size(); i += 2) {
		if (mDeqArr[i - 1] > mDeqArr[i]) {
			mDeqArrSmall.push_back(mDeqArr[i]);
			mDeqArrLarge.push_back(mDeqArr[i - 1]);
		}
		else {
			mDeqArrSmall.push_back(mDeqArr[i - 1]);
			mDeqArrLarge.push_back(mDeqArr[i]);
		}
	}
	if (mDeqArr.size() % 2 != 0)
		mDeqArrSmall.push_back(mDeqArr.back());
}

/*Recursively orders number sequence of larger numbers vector with innsertion sort
  Initial n is vector size.*/
void PmergeMe::sortRecursivelyVec(std::vector<int>& vecArr, int n)
{
	if (n <= 1)
		return;
	sortRecursivelyVec(vecArr, n - 1);
	int last = vecArr[n - 1];
	int j = n - 2;
	while (j >= 0 && vecArr[j] > last)
	{
		vecArr[j + 1] = vecArr[j];
		j--;
	}
	vecArr[j + 1] = last;
}

/*Deque implementation of above function*/
void PmergeMe::sortRecursivelyDeq(std::deque<int>& deqArr, int n)
{
	if (n <= 1)
		return;
	sortRecursivelyDeq(deqArr, n - 1);
	int last = deqArr[n - 1];
	int j = n - 2;
	while (j >= 0 && deqArr[j] > last)
	{
		deqArr[j + 1] = deqArr[j];
		j--;
	}
	deqArr[j + 1] = last;
}

/*Function creates initial array with the 2 first Jacobsthal numbers, then creates further numbers
  as long as the new number is smaller than the passed integer n, which is the size of the smaller
  numbers vector. Next number of sequence is always current number + 2 * prev number of the sequence.*/
std::vector<int> PmergeMe::generateJacobsthalNumbersVec(int n) {
	std::vector<int> jacobsthalArray = {1, 1};
	while (true) {
		int newNumber = (jacobsthalArray[jacobsthalArray.size() - 2] * 2) + jacobsthalArray.back();
		if (newNumber >= n) {
			break;
		}
		jacobsthalArray.push_back(newNumber);
	}
	return (jacobsthalArray);
}

/*Deque implementation of above function*/
std::deque<int> PmergeMe::generateJacobsthalNumbersDeq(int n) {
	std::deque<int> jacobsthalArray = {1, 1};
	while (true) {
		int newNumber = (jacobsthalArray[jacobsthalArray.size() - 2] * 2) + jacobsthalArray.back();
		if (newNumber >= n) {
			break;
		}
		jacobsthalArray.push_back(newNumber);
	}
	return (jacobsthalArray);
}

/*First generates Jacobsthal numbers based on small numbers vector size. Then loops through
  Jacobsthal array and checks depending on the current Jacobsthal number, how many numbers
  of the small numbers array shall be inserted into the large numbers array. In case this method
  does not cover all numbers of the small numbers array (if there are not enough numbers left
  in the array matching the current Jacobsthal number), the rest of the numbers is inserted
  step by step.*/
void PmergeMe::jacobsthalInsertionVec(std::vector<int>& large, std::vector<int>& small) {
	std::vector<int>jacobsthalArray = generateJacobsthalNumbersVec(small.size());
	size_t j = 0;
	size_t insertedNumbers = 0;
	
	for (size_t i = 0; i < jacobsthalArray.size(); i++) {
		for (; static_cast<size_t>(jacobsthalArray[i]) < small.size() - insertedNumbers; j++) {
			auto it = std::lower_bound(large.begin(), large.end(), small[j]);
			large.insert(it, small[j]);
			insertedNumbers++;
		}
	}
	while (small.size() - insertedNumbers != 0) {
		auto it = std::lower_bound(large.begin(), large.end(), small[insertedNumbers]);
		large.insert(it, small[insertedNumbers]);
		insertedNumbers++;
	}
}

/*Deque implementation of above function*/
void PmergeMe::jacobsthalInsertionDeq(std::deque<int>& large, std::deque<int>& small) {
	std::deque<int>jacobsthalArray = generateJacobsthalNumbersDeq(small.size());
	size_t j = 0;
	size_t insertedNumbers = 0;
	
	for (size_t i = 0; i < jacobsthalArray.size(); i++) {
		for (; static_cast<size_t>(jacobsthalArray[i]) < small.size() - insertedNumbers; j++) {
			auto it = std::lower_bound(large.begin(), large.end(), small[j]);
			large.insert(it, small[j]);
			insertedNumbers++;
		}
	}
	while (small.size() - insertedNumbers != 0) {
		auto it = std::lower_bound(large.begin(), large.end(), small[insertedNumbers]);
		large.insert(it, small[insertedNumbers]);
		insertedNumbers++;
	}
}

void	PmergeMe::mergeSortVector()	{
	std::cout << "++++Vector++++" << std::endl;
	std::cout << "Before:  ";
	for (auto it = mVecArr.begin(); it < mVecArr.end(); it++) {
		if (mVecArr.size() > 20 && it == mVecArr.begin() + 20) {
				std::cout << "[...]" << std::endl;
				break;
		}
		if (it == mVecArr.end() - 1)
			std::cout << *it << std::endl;
		else
			std::cout << *it << " ";
	}
	splitIntoSmallAndLargeVec();
	sortRecursivelyVec(mVecArrLarge, mVecArrLarge.size());
	jacobsthalInsertionVec(mVecArrLarge, mVecArrSmall);
	std::cout << "After:   ";
	for (auto it = mVecArrLarge.begin(); it < mVecArrLarge.end(); it++) {
		if (mVecArrLarge.size() > 20 && it == mVecArrLarge.begin() + 20) {
				std::cout << "[...]" << std::endl;
				break;
		}
		if (it == mVecArrLarge.end() - 1)
			std::cout << *it << std::endl;
		else
			std::cout << *it << " ";
	}
}

/*Deque implementation of above function*/
void	PmergeMe::mergeSortDeque()	{
	std::cout << "++++Deque++++" << std::endl;
	std::cout << "Before:  ";
	for (auto it = mDeqArr.begin(); it < mDeqArr.end(); it++) {
		if (mDeqArr.size() > 20 && it == mDeqArr.begin() + 20) {
				std::cout << "[...]" << std::endl;
				break;
		}
		if (it == mDeqArr.end() - 1)
			std::cout << *it << std::endl;
		else
			std::cout << *it << " ";
	}
	splitIntoSmallAndLargeDeq();
	sortRecursivelyDeq(mDeqArrLarge, mDeqArrLarge.size());
	jacobsthalInsertionDeq(mDeqArrLarge, mDeqArrSmall);
	std::cout << "After:   ";
	for (auto it = mDeqArrLarge.begin(); it < mDeqArrLarge.end(); it++) {
		if (mDeqArrLarge.size() > 20 && it == mDeqArrLarge.begin() + 20) {
				std::cout << "[...]" << std::endl;
				break;
		}
		if (it == mDeqArrLarge.end() - 1)
			std::cout << *it << std::endl;
		else
			std::cout << *it << " ";
	}
}
