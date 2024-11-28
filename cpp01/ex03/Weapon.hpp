/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:58:02 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/28 08:52:04 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
private:
	std::string	mType;

public:
	//Constructor
	Weapon(std::string type);
	//Deconstructor
	~Weapon();
	//Methods
	const 	std::string& getType() const;
	void	setType(const std:: string& type);
};

#endif