/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:43 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/28 09:10:21 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
private:
	Weapon&		mWeapon;	
	std::string	mName;

public:
	//Constructor
	HumanA(std::string name, Weapon& weapon);
	//Deconstructor
	~HumanA();
	//Methods
	void	attack();
};

#endif
