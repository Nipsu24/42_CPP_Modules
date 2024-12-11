/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/11 15:19:22 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	Cat("Tom"); //calls constructor
	ScavTrap	Mouse("Jerry"); //calls constructor and ScavTrap constructor
	ScavTrap	Cricket(Mouse); //calls Copy Constructor and ScavTrap copy constructor
	
	Cricket = Mouse; // calls ScavTrap copy assignment operator and copy assignment operator

	Cat.attack("a mouse");
	Mouse.attack("a cat");
	Cat.takeDamage(5);
	Mouse.takeDamage(20);
	Mouse.guardGate();
	Cat.beRepaired(2);
	Cat.attack("a mouse");
	Cat.takeDamage(1);
	Cat.attack("a mouse");
	Cat.takeDamage(1);
	Mouse.beRepaired(5);
	Mouse.guardGate();
	Cat.attack("a mouse");
	Cat.attack("a mouse");
	Cat.attack("a mouse");
	Cat.attack("a mouse");
	Cat.attack("a mouse");
	Cat.beRepaired(2);
	Cat.attack("a mouse");
	//calls ScavTrap destructor, cleans up derived class-specific members (for cricket)
	//calls destructor, cleans up base part class (for cricket)
	//calls ScavTrap destructor (for mouse)
	//calls destructor (for mouse)
	//calls destructor (for cat)
	//->derived class gets always destroyed before base class in order to avoid undefined states (as it relies
	//  on members/resources initialised in the base class)
	return (0);
}