/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:38:35 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/02 10:56:29 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Parameterized constructor, populates member varialbe 'name' of zombie class
  with passed name when class is created.*/
Zombie::Zombie(std::string zombieName) : name(zombieName) {}


/*Deconstructor, prints out respective phrase when zombie class gets destroyed.*/
Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " has been destroyed.\n";
}

/*Prints out respective phrase including value of member variable 'name'
  of zombie class.*/
void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
