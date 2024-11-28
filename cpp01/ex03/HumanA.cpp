/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:39 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/28 10:11:02 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*Constructor taking both, weapon and name as arguments.*/
HumanA::HumanA(std::string name, Weapon& weapon) : mWeapon(weapon), mName(name) {}

/*Deconstructor with empty body.*/
HumanA::~HumanA() {
	std::cout << mName << "'s attacks aren't very effective..." << std::endl;
}

void HumanA::attack(void)
{
	std::cout << mName << " attacks with his " << mWeapon.getType() << std::endl; 
}
