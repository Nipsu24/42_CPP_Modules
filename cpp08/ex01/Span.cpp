/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:19:24 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/11 14:46:20 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <limits>

Span::Span() : mElements(0) {}

/*Checks if N is equal 0 and throws exception if this is the case. Cannot protect
  against passing negative numbers as conversion into unsigned int results in high
  positive number.*/
Span::Span(unsigned int N) : mArray() {
	if (N <= 0 || N > std::numeric_limits<int>::max())
		throw std::invalid_argument("Array size must be greater than 0 and int_max.");
	mElements = N;
}

Span::Span(const Span& other) : mElements(other.mElements), mArray(other.mArray) {}

Span& Span::operator=(const Span& other) {
	if (this == &other)
		return (*this);
	mElements = other.mElements;
	mArray = other.mArray;
	return (*this);
}

Span::~Span() {}

/*Custom exception in case array has already reached limit*/
const char*	Span::ArrayFullException::what() const noexcept {
	return ("Already sufficient amount of elements in array.");
}

const char*	Span::NotEnoughElementsException::what() const noexcept {
	return ("Not enough elements in array for calculating span.");
}

/*Adds single number via push_back to the end of the array. Checks first
  if there is still 'enough space' in the array before adding the number*/
void	Span::addNumber(const int singleNumber) {
	if (mArray.size() >= mElements)
		throw ArrayFullException();
	mArray.insert(singleNumber);
}

/*First checks if more than 1 element is in the array, then sets shortest span to max int value
  as comparison start. As std::set is used as container, the set of numbers is already sorted by
  default. Creates iterator 'it' via auto and sets it to the start of the array. Also
  generates iterator to the next member and checks that it is not the end of the array. Iterates
  and substracts each member with the next member and compares result with previously stored.*/
int Span::shortestSpan() {
	if (mElements < 2)
		throw NotEnoughElementsException();
	int shortestSpan = std::numeric_limits<int>::max();
	for (auto it = mArray.begin(); std::next(it) != mArray.end(); ++it) {
		int difference = *std::next(it) - *it;
		if (difference < shortestSpan)
			shortestSpan = difference;
	}
	return (shortestSpan);
}

/*Same check as with shortestSpan, then calculates difference between reversed begin (end) of set
  and beginning of set. As std::set does not support direct random access, one cannot use e.g.
  .end() -1. Also .back() is not supported.
  .*/
int Span::longestSpan() {
	if (mElements < 2)
		throw NotEnoughElementsException();
	int longestSpan = *mArray.rbegin() - *mArray.begin();
	return (longestSpan);
}

/*Checks with substraction whether arguments have been passed correctly, then calls
  addNumber function to populate array, incl. start and end of sequence.*/
void	Span::addSpan(int start, int end) {
	int i = end - start;
	if (i < 0) {
		std::cout << "Error. Invalid span passed to function." << std::endl;
		return;
	}
	try {
		for (; start <= end; start++) {
			addNumber(start);
		}
	}
	catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
	}
}
