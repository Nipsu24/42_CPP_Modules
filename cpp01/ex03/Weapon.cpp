/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:59 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/27 16:03:00 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/*Constructor taking weapon type as argument.*/
Weapon::Weapon(std::string type) : mType(type) {}

/*Deconstructor with empty body.*/
Weapon::~Weapon() {}

/*getter function*/
const 	std::string& Weapon::getType() const {return mType;}

/*setter function*/
void	Weapon::setType(std::string type) {mType = type;}
