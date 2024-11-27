/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:48 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/27 16:17:42 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*Constructor taking only the name, not the weapon as argument.*/
HumanB::HumanB(std::string name) : mName(name) {}

/*Deconstructor with empty body.*/
HumanB::~HumanB() {}

void HumanB::attack(void)
{
	std::cout << mName << " attacks with their " << mWeapon.getType() << std::endl; 
}

void	HumanB::setWeapon(class Weapon newWeapon)
{
	mWeapon = newWeapon;
}