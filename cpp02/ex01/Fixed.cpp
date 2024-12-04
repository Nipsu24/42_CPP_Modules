/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:21:32 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/04 14:55:22 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "iomanip"
#include <cmath>

/*constructor*/
Fixed::Fixed() : mRawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

//Parameterized constructor I (int)
Fixed::Fixed(const int n){
	std::cout << "Int constructor called" << std::endl;
	mRawBits = n * (1 << mFractionalBitsAmount);
}

//Parameterized constructor II (float)
Fixed::Fixed(const float n){
	std::cout << "Float constructor called" << std::endl;
	mRawBits = static_cast<int>(roundf(n * (1 << mFractionalBitsAmount)));
	
}

/*copy-constructor*/
Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	mRawBits = other.getRawBits();
}

/*copy assignment operator*/
Fixed& Fixed::operator=(const Fixed& other){
	if (this == &other)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	mRawBits = other.getRawBits();
	return (*this);
}

/*deconstructor*/
Fixed::~Fixed(){
	std::cout << "Destructor called " << *this << std::endl;
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (mRawBits);
}

void	Fixed::setRawBits(int const raw)
{
	 mRawBits = raw;
}

float	Fixed::toFloat(void) const
{
	float	floatValue;

	floatValue = static_cast<float>(mRawBits) / (1 << mFractionalBitsAmount); // 1 << 8 is equal to 2^8 (binary: 100000000)
	return (floatValue);
}

int	Fixed::toInt(void) const
{
	int	intValue;

	intValue = roundf(mRawBits / (1 << mFractionalBitsAmount));
	return (intValue);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat(); // Convert fixed-point to float and write to stream
	return os;             // Return the stream to allow chaining (e.g., cout << obj1 << obj2)
}