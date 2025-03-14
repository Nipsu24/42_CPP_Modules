/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:21:32 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/04 16:16:24 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*constructor*/
Fixed::Fixed() : mRawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

/*copy-constructor*/
Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	mRawBits = other.getRawBits();
}

/*copy assignment operator, called when already existing object
  is assigned a value of another existing object*/
Fixed& Fixed::operator=(const Fixed& other){
	if (this == &other)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	mRawBits = other.getRawBits();
	return (*this);
}

/*deconstructor*/
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (mRawBits);
}

void	Fixed::setRawBits(int const raw)
{
	 mRawBits = raw;
}
