/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/11 16:03:13 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	Cat("Tom"); //calls constructor
	ScavTrap	Mouse("Jerry"); //calls constructor and ScavTrap constructor
	FragTrap	Cricket("Jiminy"); //calls constructor and FragTrap constructor
	
	Cat.attack("a mouse");
	Mouse.attack("a cat");
	Cricket.attack("an ant");
	Cat.takeDamage(5);
	Cricket.takeDamage(40);
	Cricket.highFivesGuys();
	Cat.beRepaired(2);
	Cat.attack("a mouse");
	Cat.takeDamage(1);
	Cat.attack("a mouse");
	Cat.takeDamage(1);
	Cricket.beRepaired(5);
	Cricket.highFivesGuys();
	Cat.attack("a mouse");
	Cat.attack("a mouse");
	Cat.attack("a mouse");
	Cat.attack("a mouse");
	Cat.attack("a mouse");
	Cat.beRepaired(2);
	Cat.attack("a mouse");
	return (0);
}