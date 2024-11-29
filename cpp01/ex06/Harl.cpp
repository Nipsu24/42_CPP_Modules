/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:55:18 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/29 12:32:00 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout << "[DEBUG LEVEL] : Spamming printf is the most effective debugging method." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO LEVEL] : Test1, Test2, Test6, Test 4, Test4." << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING LEVEL] : Use of invalid specifier in printf." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR LEVEL] : ***Segfault***." << std::endl;
}

/*Initiates an array with the respective levels. Loops through this array and
  - in case level passed to function and level within the array match - assigns
  value of iterator 'i'  to levelCode variable which is used afterwards in switch
  statement. Commented out lines show further possible approaches/notation options.
  Default prints fallback phrase if 'i' is not holding any value of a defined case.*/
void	Harl::complain(std::string level)
{
	// void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int			levelCode = -1;
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			levelCode = i;
	}
	switch(levelCode)
	{
		case 0:
			debug();
			//other quotations that would do the same:
			// (this->*functions[0])();
			// Harl::debug();
			// this->debug();
			info();
			warning();
			error();
			break;
		case 1:
			info();
			warning();
			error();
			break;
		case 2:
			warning();
			error();
			break;
		case 3:
			error();
			break;
		default:
			std::cout << "[UNKNOWN LEVEL] : Level unknown to Harl 2.0" << std::endl;		
	}
}
