/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:55:18 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/29 12:23:38 by mmeier           ###   ########.fr       */
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

/*Creates function pointer array to the respective member functions. Then initiates
  an array with the corresponding levels. Loops through this array and calls matching
  function via 'this->' (used for invoking member functions on the specific object
  instance). A fallback phrase is printed in case no match is found.*/
void	Harl::complain(std::string level)
{
	void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for(int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "[UNKNOWN LEVEL] : Level unknown to Harl 2.0" << std::endl;
}
