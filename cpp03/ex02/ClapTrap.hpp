/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:09:19 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/11 13:25:41 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	protected:
		std::string	mName;
		int			mHitPoints;
		int			mEnergyPoints;
		int			mAttackDamage;
	
	public:
		//Constructor
		ClapTrap(std::string name);
		//Copy constructor
		ClapTrap(const ClapTrap& other);
		//Copy assignment operator
		ClapTrap& operator=(const ClapTrap& other);
		//Destructor
		~ClapTrap();
		
		//Methods:
		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif
