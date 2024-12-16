/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:41:08 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/16 12:05:55 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*Constructor*/
Animal::Animal() : mType("Pet")
{
	std::cout << "Base Constructor called" << std::endl;
}

/*Copy Constructor*/
Animal::Animal(const Animal& other)
{
	std::cout << "Base Copy Constructer called." << std::endl;
	mType = other.mType;
}

/*Copy assignment operator*/
Animal& Animal::operator=(const Animal& other)
{
	if (this == &other)
		return (*this);
	std::cout << "Base Copy Assignment Operator called." <<std::endl;
	mType = other.mType;
	return (*this);
}

/*Destructor*/
Animal:: ~Animal(){std::cout << "Base Destructor called" << std::endl;}

std::string	Animal::getType() const {return (mType);}

/*no longer needed, as defined as pure virtual function in header file*/
// void	Animal::makeSound() const
// {
// 	std::cout << mType << " does not make a noise." << std::endl;
// }