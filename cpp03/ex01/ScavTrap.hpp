/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:09:19 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/10 17:09:38 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {
	public:
		/*Constructor (custom made for ScavTrap, constsructors generally not inherited)*/
		ScavTrap(std::string name);
		/*Copy constructor (not inherited from ClapTrap)*/
		ScavTrap(const ScavTrap& other);
		/*Copy assignment operator (not inherited from ClapTrap)*/
		ScavTrap& operator=(const ScavTrap& other);
		/*Desctructor (custom made for ScavTrap, destructors generally not inherited)*/
		~ScavTrap();
		
		//Methods:
		void	guardGate();
};

#endif
