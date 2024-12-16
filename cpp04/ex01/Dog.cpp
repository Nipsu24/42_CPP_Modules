/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:41:40 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/16 11:03:37 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*Constructor*/
Dog::Dog() : Animal()
{
	std::cout << "Dog Constructor called" << std::endl;
	mType = "Dog";
	mDogBrain = new Brain();
}

/*Copy Constructor*/
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog Copy Constructer called." << std::endl;
	mType = other.mType;
	mDogBrain = new Brain(*other.mDogBrain);
}

/*Copy assignment operator*/
Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	std::cout << "Dog Copy Assignment Operator called." <<std::endl;
	Animal::operator=(other);
	mType = other.mType;
	delete mDogBrain;
	mDogBrain = new Brain(*other.mDogBrain);
	return (*this);
}

/*Destructor*/
Dog:: ~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete mDogBrain;
}

void	Dog::makeSound() const
{
	std::cout << "Wuff Wuff Wuff" << std::endl;
}

Brain&	Dog::getBrain(){return (*mDogBrain);}
