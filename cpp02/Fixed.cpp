/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:21:32 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/02 14:55:48 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*constructor*/
Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

/*copy-constructor*/
Fixed::Fixed(const Fixed& other) : value(other.value) {
	std::cout << "Copy constructor called" << std::endl;
}

/*copy assignment operator*/
Fixed& Fixed::operator=(const Fixed& other){
	value = other.value;
	std::cout << "Copy assignment operator called" << std::endl;
}

/*deconstructor*/
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	
}

void	Fixed::setRawBits(int const raw)
{
	
}