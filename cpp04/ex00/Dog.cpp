/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:41:40 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/12 15:45:29 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*Constructor*/
Dog::Dog() : Animal()
{
	std::cout << "Dog Constructor called" << std::endl;
	mType = "Dog";
}

/*Copy Constructor*/
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog Copy Constructer called." << std::endl;
	mType = other.mType;
}

/*Copy assignment operator*/
Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	std::cout << "Dog Copy Assignment Operator called." <<std::endl;
	Animal::operator=(other);
	mType = other.mType;
	return (*this);
}

/*Destructor*/
Dog:: ~Dog(){std::cout << "Dog Destructor called" << std::endl;}

void	Dog::makeSound() const
{
	std::cout << "Wuff Wuff Wuff" << std::endl;
}