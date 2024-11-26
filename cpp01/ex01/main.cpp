/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:38:18 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/26 16:23:48 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Calls zombieHorde function in order to create j amount of zombie classes.
  In case memory allocation fails (e.g. j is negative), returns 1. Prints
  each created zombie via announce function. Frees allocated memory via
  delete[] function.*/
Zombie*	zombieHorde(int N, std:: string name);

int	main(void)
{
	// int	j = -1;
	// int j = 0;
	int j = 3;
	Zombie*	horde = zombieHorde(j, "Shawn");
	if (!horde)
		return (1);
	for(int i = 0; i < j; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
