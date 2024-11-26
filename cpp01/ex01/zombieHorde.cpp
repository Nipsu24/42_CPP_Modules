/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:17:02 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/26 16:26:18 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Initialises horde array for N amount of zombie classes. Uses try/catch
  for checking whether memory allocation failed (e.g. if N is negative) and
  returns nullpointer in this case. If allocation was successful, calls 
  setter function for populating 'name' member variable of zombie class.*/
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