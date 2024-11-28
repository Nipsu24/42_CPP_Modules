/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:55 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/28 11:07:56 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

/*The two parts of the code structured within two '{}' create two independent
  scopes. Therefore it is possible to e.g. instanciate the Weapon class twice,
  both independently created, used and destroyed. Class HumanA contains a 
  reference to a weapon class, whereby HumanB a pointer to a weapon class,
  which makes it possible that HumanB does not necessarily need to have a
  weapon (weapon can be a nullpointer and is not part of HumanB constructor).
  HumanA cannot 'exist' without a weapon, as the weapon is declared as a
  reference within the HumanA class and always need to refer to a valid object.
  Furthermore it ispart of the HumanA constructor.*/
int	main(void)
{
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("rusty iron club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");
		HumanB	jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		std::cout << "...but then out of nowhere..." << std::endl;
		jim.attack();
		club.setType("fragile wood club");
		jim.attack();
	}
	
	return (0);
}
