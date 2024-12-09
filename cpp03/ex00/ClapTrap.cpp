/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:08:44 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/09 16:41:14 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*Constructor*/
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor called." << std::endl;
	mName = name;
}

/*Copy-Constructor*/
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy Constructer called." << std::endl;
	mName = other.mName;
}

/*Copy assignment operator*/
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this == &other)
		return (*this);
	std::cout << "Copy assignment operator called." <<std::endl;
	mName = other.mName;
	return (*this);
}

/*Destructor*/
ClapTrap:: ~ClapTrap(){std::cout << "Destructor called" << std::endl;}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap" << mName << " attacks " << target << ", causing " <<  mAttackDamage << "of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap" << mName << " takes " << amount << ", amount of damage!" << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap" << mName << " repairs itself and gets " << amount << ", hit points back!" << std::endl;
}