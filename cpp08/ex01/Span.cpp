/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:19:24 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/10 17:14:18 by mmeier           ###   ########.fr       */
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
	if (N <= 0)
		throw std::invalid_argument("Array size must be greater than 0.");
	else
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
	mArray.push_back(singleNumber);
}

int Span::shortestSpan() {
	if (mElements < 2)
		throw NotEnoughElementsException();
	std::sort(mArray.begin(), mArray.end());
	for (size_t i = 0; i < mArray.size(); i++)
		std::cout << mArray[i] << std::endl;
	int shortestSpan = std::numeric_limits<int>::max();
	int difference = 0;
	for (size_t i = 1; i < mArray.size(); i++) {
		difference = mArray[i] - mArray[i -1];
		if (difference < shortestSpan)
			shortestSpan = difference;
	}
	return (shortestSpan);
}