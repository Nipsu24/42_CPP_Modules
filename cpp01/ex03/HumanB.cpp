/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:48 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/28 11:02:12 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*Constructor taking only the name, not the weapon as argument.
  Weapon member is initialised as nullptr.*/
HumanB::HumanB(std::string name) : mWeapon(nullptr), mName(name) {}

/*Deconstructor with empty body.*/
HumanB::~HumanB() {
	std::cout << mName << " has no strenght anymore but is satisfied with the result." << std::endl;
}

/*Prints out attack phrase if weapon class pointer within HumanB class is not null.*/
void HumanB::attack(void)
{
	if (mWeapon)
		std::cout << mName << " attacks with his " << mWeapon->getType() << std::endl;
	else
		std::cout << mName << " has no weapon to attack with" << std::endl; 
}

/*Setter function, assigns address of passed weapon reference to weapon member
  of HumanB class.*/
void	HumanB::setWeapon(Weapon& weapon) {mWeapon = &weapon;}