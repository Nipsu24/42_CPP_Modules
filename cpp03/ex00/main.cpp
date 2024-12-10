/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/10 14:18:16 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Cat("Tom");

	Cat.attack("Jerry");
	Cat.takeDamage(5);
	Cat.beRepaired(2);
	Cat.attack("Jerry");
	Cat.takeDamage(1);
	Cat.attack("Jerry");
	Cat.takeDamage(1);
	Cat.attack("Jerry");
	Cat.attack("Jerry");
	Cat.attack("Jerry");
	Cat.attack("Jerry");
	Cat.attack("Jerry");
	Cat.beRepaired(2);
	Cat.attack("Jerry");
	Cat.attack("Jerry");
	Cat.attack("Jerry");
	Cat.attack("Jerry");
	return (0);
}