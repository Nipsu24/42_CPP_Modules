/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:52 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/28 10:45:06 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
	Weapon*		mWeapon;	
	std::string	mName;

public:
	//Constructor
	HumanB(std::string name);
	//Deconstructor
	~HumanB();
	//Methods
	void	attack();
	void	setWeapon(Weapon& weapon);
};

#endif
