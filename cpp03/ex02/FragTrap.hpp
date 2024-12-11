/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:40:28 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/11 15:44:17 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
	public:
		/*Constructor (custom made for FragTrap, constsructors generally not inherited)*/
		FragTrap(std::string name);
		/*Copy constructor (not inherited from ClapTrap)*/
		FragTrap(const FragTrap& other);
		/*Copy assignment operator (not inherited from ClapTrap)*/
		FragTrap& operator=(const FragTrap& other);
		/*Desctructor (custom made for FragTrap, destructors generally not inherited)*/
		~FragTrap();
		
		//Methods:
		void	highFivesGuys(void);
		void	attack(const std::string& target) override;
};

#endif