/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:48:35 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/09 13:17:20 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<class T>
class Array {
	private:
	T*		mPtr;
	size_t	mSize;
	
	public:
	//constructor
	Array() : mPtr(nullptr), mSize(0) {}

	//parameterized constructor
	Array(unsigned int n) : mPtr(new T[n]()), mSize(n) {
		for (size_t i = 0; i < n; i++) {
			mPtr[i] = T();
		}
	}

	//copy-constructor
	Array(const Array<T>& other) {
		mSize = other.mSize;
		mPtr = new T[other.mSize];
		for (size_t i = 0; i < mSize; i++) {
			mPtr[i] = other.mPtr[i];
		}
	}

	//copy assignemnt operator
	Array<T>& operator=(const Array<T>& other) {
		if (this == &other)
			return (*this);
		delete[] mPtr;
		mSize = other.mSize;
		mPtr = new T[other.mSize];
		for (size_t i = 0; i < mSize; i++) {
			mPtr[i] = other.mPtr[i];
		}
		return (*this);
	}

	//destructor
	~Array() {
		delete[] mPtr;
	}

	/*Returns size of array*/
	size_t size() const { return (mSize); }

	/*Hanldes []-operator in a mutable version*/
	T& operator[](size_t index) {
		if (index >= mSize)
			throw std::out_of_range("Index out of bounds");
		return (mPtr[index]);
	}

	/*Hanldes []-operator in a non-mutable version*/
	const T& operator[](size_t index) const {
		if (index >= mSize)
			throw std::out_of_range("Index out of bounds");
		return (mPtr[index]);
	}
};

#endif