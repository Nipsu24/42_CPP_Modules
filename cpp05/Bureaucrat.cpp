/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:06:32 by mmeier            #+#    #+#             */
/*   Updated: 2025/01/13 15:11:15 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*Constructor*/
Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade < 1 )
		GradeTooHighException()
	if (grade > 150)
		GradeTooLowException
}

/*Copy Constructor*/
Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	std::cout << "Base Copy Constructer called." << std::endl;
	mType = other.mType;
}

/*Copy assignment operator*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return (*this);
	std::cout << "Base Copy Assignment Operator called." <<std::endl;
	mType = other.mType;
	return (*this);
}

/*Destructor*/
Bureaucrat:: ~Bureaucrat(){std::cout << "Base Destructor called" << std::endl;}

std::string	Bureaucrat::getType() const {return (mType);}

void	Bureaucrat::makeSound() const
{
	std::cout << mType << " does not make a noise." << std::endl;
}