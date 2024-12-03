/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:21:32 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/03 15:10:16 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*constructor*/
Fixed::Fixed() : mValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

//Parameterized constructor I
Fixed::Fixed(const int n){
	
}

//Parameterized constructor II
Fixed::Fixed(const float n){
	
}

/*copy-constructor*/
Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	mValue = other.getRawBits();
}

/*copy assignment operator*/
Fixed& Fixed::operator=(const Fixed& other){
	if (this == &other)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	mValue = other.getRawBits();
	return (*this);
}

/*deconstructor*/
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (mValue);
}

void	Fixed::setRawBits(int const raw)
{
	 mValue = raw;
}

float	Fixed::toFloat(void) const
{
	
}

int	Fixed::toInt(void) const
{
	
}
