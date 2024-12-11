/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:08:44 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/11 15:03:38 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*Constructor*/
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor called." << std::endl;
	mName = name;
	mHitPoints = 100;
	mEnergyPoints = 50;
	mAttackDamage = 20;
}

/*Copy-Constructor*/
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constructer called." << std::endl;
	mName = other.mName;
	mHitPoints = 100;
	mEnergyPoints = 50;
	mAttackDamage = 20;
}

/*Copy assignment operator, call to ClapTrap base class operator needed
  in order to ensure that base class members are properly handled. Derived
  class specific modifications handled by 'ScavTrap::operator='*/
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this == &other)
		return (*this);
	std::cout << "ScavTrap Copy assignment operator called." <<std::endl;
	ClapTrap::operator=(other);
	mName = other.mName;
	mHitPoints = 100;
	mEnergyPoints = 50;
	mAttackDamage = 20;
	return (*this);
}

/*Destructor*/
ScavTrap:: ~ScavTrap(){std::cout << "ScavTrap Destructor called" << std::endl;}

/*ScavTrap attack function which overrides ClapTraps attack function (override keyword in .hpp file and virual function in ClapTrap.hpp)*/
void ScavTrap::attack(const std::string& target)
{
	if (mEnergyPoints > 0 && mHitPoints > 0)
	{
		mEnergyPoints = mEnergyPoints - 1;
		std::cout << "ScavTrap " << mName << " attacks " << target << ", causing " << mAttackDamage << " amount of damage!" << std::endl;
		std::cout << "... and has now " << mEnergyPoints << " energy points left!" << std::endl;
	}
	else if (mEnergyPoints <= 0)
		std::cout << "ScavTrap " << mName << " cannot attack as it does not have any energy points left!" << std::endl;
	else if (mHitPoints <= 0)
		std::cout << "ScavTrap " << mName << " cannot attack as it does not have any hit points left!" << std::endl;
}

/*Member function of ScavTrap printing gate keeper mode phrase*/
void	ScavTrap::guardGate(){std::cout << "ScavTrap " << mName << " is in Gate Keeper Mode." << std::endl;}