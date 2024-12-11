/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:08:44 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/11 15:21:10 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*Constructor*/
ClapTrap::ClapTrap(std::string name) : mHitPoints(10), mEnergyPoints(10), mAttackDamage(0)
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

/*Checks whether sufficient amount of energy and hit points are available and then 'attacks',
  otherwise prints respective statement if not sufficient points available.*/
void	ClapTrap::attack(const std::string& target)
{
	if (mEnergyPoints > 0 && mHitPoints > 0)
	{
		mEnergyPoints = mEnergyPoints - 1;
		std::cout << "ClapTrap " << mName << " attacks " << target << ", causing " << mAttackDamage << " amount of damage!" << std::endl;
		std::cout << "... and has now " << mEnergyPoints << " energy points left!" << std::endl;
	}
	else if (mEnergyPoints <= 0)
		std::cout << "ClapTrap " << mName << " cannot attack as it does not have any energy points left!" << std::endl;
	else if (mHitPoints <= 0)
		std::cout << "ClapTrap " << mName << " cannot attack as it does not have any hit points left!" << std::endl;
}

/*Checks amount of hit points after substraction of passed int and prints respective message (depending on typeid
  - which object called the function)*/
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (typeid(*this) == typeid(ClapTrap))
		std::cout << "ClapTrap " << mName << " gets hit and takes " << amount << " amount of damage!" << std::endl;
	else
		std::cout << "ScavTrap " << mName << " gets hit and takes " << amount << " amount of damage!" << std::endl;
	mHitPoints = mHitPoints - amount;
	if (mHitPoints > 0)
		std::cout << "... and has " << mHitPoints << " hit points left!" << std::endl;
	else
		std::cout << "...and has no hit points left!" << std::endl;
}

/*Checks whether sufficient amount of energy and hit points are available and then 'repairs',
  otherwise prints respective statement if not sufficient points available.
  Checks with typeid which object called the function and prints dedicated message.*/
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (mEnergyPoints > 0 && mHitPoints > 0)
	{
		mEnergyPoints = mEnergyPoints - 1;
		mHitPoints = mHitPoints + amount;
		if (typeid(*this) == typeid(ClapTrap))
			std::cout << "ClapTrap " << mName << " repairs itself and gets " << amount << " hit points back!" << std::endl;
		else
			std::cout << "ScavTrap " << mName << " repairs itself and gets " << amount << " hit points back!" << std::endl;
		std::cout << "... and has now " << mHitPoints << " hit points and " << mEnergyPoints << " energy points left!" << std::endl;
	}
	else if (mEnergyPoints <= 0)
	{
		if (typeid(*this) == typeid(ClapTrap))
			std::cout << "ClapTrap " << mName << " cannot repair as it does not have any energy points left!" << std::endl;
		else
			std::cout << "ScavTrap " << mName << " cannot repair as it does not have any energy points left!" << std::endl;
	}
	else if (mHitPoints <= 0)
	{
		if (typeid(*this) == typeid(ClapTrap))
			std::cout << "ClapTrap " << mName << " cannot repair as it does not have any hit points left!" << std::endl;
		else
			std::cout << "ScavTrap " << mName << " cannot repair as it does not have any energy points left!" << std::endl;
	}
		
}
