/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:38:24 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/26 16:38:09 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Dynamically allocates memory for a zombie class. Returns
  nullpointer in case of failure or pointer to class object
  in case of success. Failed memory allocation is checked 
  via try/catch.*/
Zombie* newZombie(std::string name)
{
	Zombie *zombie = nullptr;
	try
	{
		zombie =  new Zombie(name);
	}
	catch (std::bad_alloc& e)
	{
		std::cout << "Error. Memory allocation failed." << "\n";
        return nullptr;
	}
	return zombie; 
}
