/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:39 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/28 11:03:18 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*Constructor taking both, weapon (as reference) and name as arguments.*/
HumanA::HumanA(std::string name, Weapon& weapon) : mWeapon(weapon), mName(name) {}

/*Deconstructor.*/
HumanA::~HumanA() {
	std::cout << mName << "'s attacks aren't very effective..." << std::endl;
}

/*Prints out attack phrase including name of attacker and weapon type.*/
void HumanA::attack(void)
{
	std::cout << mName << " attacks with his " << mWeapon.getType() << std::endl; 
}
