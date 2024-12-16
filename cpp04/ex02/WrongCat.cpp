/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:42:47 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/12 16:14:44 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*Constructor*/
WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat Constructor called" << std::endl;
	mType = "WrongCat";
}

/*Copy Constructor*/
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat Copy Constructer called." << std::endl;
	mType = other.mType;
}

/*Copy assignment operator*/
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this == &other)
		return (*this);
	std::cout << "WrongCat Copy Assignment Operator called." <<std::endl;
	WrongAnimal::operator=(other);
	mType = other.mType;
	return (*this);
}

/*Destructor*/
WrongCat:: ~WrongCat(){std::cout << "WrongCat Destructor called" << std::endl;}
