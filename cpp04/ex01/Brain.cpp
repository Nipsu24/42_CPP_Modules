/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:06:52 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/13 16:40:35 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*Constructor*/
Brain::Brain()
{
	std::cout << "Brain Base Constructor called" << std::endl;
}

/*Copy Constructor*/
Brain::Brain(const Brain& other)
{
	std::cout << "Brain Base Copy Constructer called." << std::endl;
	mIdeas = other.mIdeas;
}

/*Copy assignment operator*/
Brain& Brain::operator=(const Brain& other)
{
	if (this == &other)
		return (*this);
	std::cout << "Brain Base Copy Assignment Operator called." <<std::endl;
	mIdeas= other.mIdeas;
	return (*this);
}

/*Destructor*/
Brain:: ~Brain(){std::cout << "Brain Base Destructor called" << std::endl;}

std::string	Brain::getIdea(int index)
{
	std::cout << mIdeas[index] << std::endl;
	return(mIdeas[index]);
}

void	Brain::setIdea(int index, std::string idea)
{
	mIdeas[index] = idea;
}