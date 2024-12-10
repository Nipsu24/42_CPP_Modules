/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:08:44 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/10 17:11:09 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ClapTrap.hpp"
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
ScavTrap::ScavTrap(const ScavTrap& other) :ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constructer called." << std::endl;
	mName = other.mName;
}

/*Copy assignment operator*/
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this == &other)
		return (*this);
	std::cout << "ScavTrap Copy assignment operator called." <<std::endl;
	mName = other.mName;
	return (*this);
}

/*Destructor*/
ScavTrap:: ~ScavTrap(){std::cout << "ScavTrap Destructor called" << std::endl;}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is in Gate Keeper Mode." << std::endl;
}