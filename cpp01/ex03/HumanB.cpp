/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:48 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/28 10:05:56 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*Constructor taking only the name, not the weapon as argument.*/
HumanB::HumanB(std::string name) :  mWeapon(nullptr), mName(name) {}

/*Deconstructor with empty body.*/
HumanB::~HumanB() {
	std::cout << mName << " has no strenght anymore but is satisfied with the result." << std::endl;
}

void HumanB::attack(void)
{
	if (mWeapon)
		std::cout << mName << " attacks with his " << mWeapon->getType() << std::endl;
	else
		std::cout << mName << " has no weapon to attack with" << std::endl; 
}

void	HumanB::setWeapon(Weapon& weapon) {mWeapon = &weapon;}