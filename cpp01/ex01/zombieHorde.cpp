/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:17:02 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/26 16:02:32 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std:: string name)
{
	Zombie* horde = nullptr;
	try
	{
		horde = new Zombie[N];
	}
	catch (std::bad_alloc& e)
	{
		std::cout << "Error. Memory allocation failed." << "\n";
        return nullptr;
	}
	for(int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}