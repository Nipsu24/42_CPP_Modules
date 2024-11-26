/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:38:18 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/26 16:34:22 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

/*Initialises zombie class with dynamic memory allocation via newZombie function (heap)
  and with randomChump function (stack). Zombies "announces" themselves with announce
  function. Allocated memory for zombieAlloct gets freed with delete operator.*/
int	main(void)
{
	Zombie	*zombieAlloct = newZombie("Shawn");
	if (!zombieAlloct)
		return (1);
	zombieAlloct->announce();
	randomChump("Rando");
	delete zombieAlloct;
	return (0);
}
