/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:48:35 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/09 14:29:51 by mmeier           ###   ########.fr       */
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

	/*parameterized constructor
	  new T[n]() ensures that all values are value initialised (and not default initialised with garbage values)
	  with their default values (int 0, double 0.0 etc.)*/
	Array(unsigned int n) : mPtr(new T[n]()), mSize(n) {}

	//copy-constructor
	Array(const Array<T>& other) {
		mSize = other.mSize;
		mPtr = new T[other.mSize];
		for (size_t i = 0; i < mSize; i++) {
			mPtr[i] = other.mPtr[i];
		}
	}

	/*copy assignemnt operator
	  Delete is actually only needed if parameterized constructor (with new) instead of constructor
	  has been used but delete nllptr is safe to use in C++*/
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