/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:40:43 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/11 15:58:22 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*Constructor*/
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Constructor called." << std::endl;
	mName = name;
	mHitPoints = 100;
	mEnergyPoints = 100;
	mAttackDamage = 30;
}

/*Copy-Constructor*/
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy Constructer called." << std::endl;
	mName = other.mName;
	mHitPoints = 100;
	mEnergyPoints = 100;
	mAttackDamage = 30;
}

/*Copy assignment operator, call to ClapTrap base class operator needed
  in order to ensure that base class members are properly handled. Derived
  class specific modifications handled by 'FragTrap::operator='*/
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this == &other)
		return (*this);
	std::cout << "FragTrap Copy assignment operator called." <<std::endl;
	ClapTrap::operator=(other);
	mName = other.mName;
	mHitPoints = 100;
	mEnergyPoints = 100;
	mAttackDamage = 30;
	return (*this);
}

/*Destructor*/
FragTrap:: ~FragTrap(){std::cout << "FragTrap Destructor called" << std::endl;}

/*FragTrap attack function which overrides ClapTraps attack function (override keyword in .hpp file and virual function in ClapTrap.hpp)*/
void FragTrap::attack(const std::string& target)
{
	if (mEnergyPoints > 0 && mHitPoints > 0)
	{
		mEnergyPoints = mEnergyPoints - 1;
		std::cout << "FragTrap " << mName << " attacks " << target << ", causing " << mAttackDamage << " amount of damage!" << std::endl;
		std::cout << "... and has now " << mEnergyPoints << " energy points left!" << std::endl;
	}
	else if (mEnergyPoints <= 0)
		std::cout << "FragTrap " << mName << " cannot attack as it does not have any energy points left!" << std::endl;
	else if (mHitPoints <= 0)
		std::cout << "FragTrap " << mName << " cannot attack as it does not have any hit points left!" << std::endl;
}

/*Member function of FragTrap printing high five phrase*/
void	FragTrap::highFivesGuys(){std::cout << "FragTrap " << mName << " requests a high five." << std::endl;}