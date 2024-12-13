/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:42:47 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/13 16:31:25 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*Constructor*/
Cat::Cat() : Animal()
{
	std::cout << "Cat Constructor called" << std::endl;
	mType = "Cat";
	CatBrain = new Brain();
}

/*Copy Constructor*/
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat Copy Constructer called." << std::endl;
	mType = other.mType;
	CatBrain = new Brain(*other.CatBrain);
}

/*Copy assignment operator*/
Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return (*this);
	std::cout << "Cat Copy Assignment Operator called." <<std::endl;
	Animal::operator=(other);
	mType = other.mType;
	delete CatBrain;
	CatBrain = new Brain(*other.CatBrain);
	return (*this);
}

/*Destructor*/
Cat:: ~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete CatBrain;
}

void	Cat::makeSound() const
{
	std::cout << "Miau Miau Miau" << std::endl;
}

Brain&	Cat::getBrain(){return (*CatBrain);}

