/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:59 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/28 09:02:52 by mmeier           ###   ########.fr       */
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
void	Weapon::setType(const std::string& type) {mType = type;}
