/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:38:24 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/26 16:14:49 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
