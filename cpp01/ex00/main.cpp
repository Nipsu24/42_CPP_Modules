/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:38:18 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/26 16:16:37 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

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
