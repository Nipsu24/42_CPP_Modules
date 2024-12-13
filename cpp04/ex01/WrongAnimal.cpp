/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:41:08 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/12 16:05:59 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*Constructor*/
WrongAnimal::WrongAnimal() : mType("Pet")
{
	std::cout << "WrongAnimal Base Constructor called" << std::endl;
}

/*Copy Constructor*/
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal Base Copy Constructer called." << std::endl;
	mType = other.mType;
}

/*Copy assignment operator*/
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this == &other)
		return (*this);
	std::cout << "WrongAnimal Base Copy Assignment Operator called." <<std::endl;
	mType = other.mType;
	return (*this);
}

/*Destructor*/
WrongAnimal:: ~WrongAnimal(){std::cout << "Base Destructor called" << std::endl;}

std::string	WrongAnimal::getType() const {return (mType);}

void	WrongAnimal::makeSound() const
{
	std::cout << mType << " does not make an animal noise." << std::endl;
}