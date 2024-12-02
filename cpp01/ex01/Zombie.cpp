/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:38:35 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/02 12:46:54 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Constructor with initialization list*/

Zombie::Zombie() : name() {}

/*Deconstructor, prints out respective phrase once a zombie class has
  been destroyed.*/
Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " has been destroyed\n";
}

/*Setter function for assigning passed name to member variable 'name'
  of zombie class.*/
void	Zombie::setName(const std::string& zombieName)
{
	name = zombieName;
}

/*Prints out respective phrase including value of member variable 'name'
  of zombie class.*/
void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
