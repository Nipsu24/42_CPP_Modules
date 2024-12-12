/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:42:47 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/12 15:45:38 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*Constructor*/
Cat::Cat() : Animal()
{
	std::cout << "Cat Constructor called" << std::endl;
	mType = "Cat";
}

/*Copy Constructor*/
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat Copy Constructer called." << std::endl;
	mType = other.mType;
}

/*Copy assignment operator*/
Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return (*this);
	std::cout << "Cat Copy Assignment Operator called." <<std::endl;
	Animal::operator=(other);
	mType = other.mType;
	return (*this);
}

/*Destructor*/
Cat:: ~Cat(){std::cout << "Cat Destructor called" << std::endl;}

void	Cat::makeSound() const
{
	std::cout << "Miau Miau Miau" << std::endl;
}