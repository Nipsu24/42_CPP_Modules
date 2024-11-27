/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:39 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/27 16:20:34 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*Constructor taking both, weapon and name as arguments.*/
HumanA::HumanA(std::string name, class Weapon) : mName(name), mWeapon(mWeapon) {}

/*Deconstructor with empty body.*/
HumanA::~HumanA() {}

void HumanA::attack(void)
{
	std::cout << mName << " attacks with their " << mWeapon.getType() << std::endl; 
}
