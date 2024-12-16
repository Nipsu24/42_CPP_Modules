/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:42:47 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/16 11:46:19 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*Constructor*/
Cat::Cat() : Animal()
{
	std::cout << "Cat Constructor called" << std::endl;
	mType = "Cat";
	mCatBrain = new Brain();
}

/*Copy Constructor*/
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat Copy Constructer called." << std::endl;
	mType = other.mType;
	mCatBrain = new Brain(*other.mCatBrain);
}

/*Copy assignment operator*/
Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return (*this);
	std::cout << "Cat Copy Assignment Operator called." <<std::endl;
	Animal::operator=(other);
	mType = other.mType;
	delete mCatBrain;
	mCatBrain = new Brain(*other.mCatBrain);
	return (*this);
}

/*Destructor*/
Cat:: ~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete mCatBrain;
}

void	Cat::makeSound() const
{
	std::cout << "Miau Miau Miau" << std::endl;
}

/*Function for accessing Brain member- used in main for further set/get idea for a cat/dog
  and for printing memory address of the Brain pointer.*/
Brain&	Cat::getBrain(){return (*mCatBrain);}

