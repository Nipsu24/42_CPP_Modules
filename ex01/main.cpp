/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:03:41 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/23 14:09:19 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	printPhoneBookHeader()
{
	std::cout << "*****************************************\n";
	std::cout << "PhoneBook Options (Enter either of them):\n";
	std::cout << "ADD\n";
	std::cout << "SEARCH\n";
	std::cout << "EXIT\n";
	std::cout << "*****************************************\n";
}

int	main()
{
	PhoneBook	phoneBook;
	std::string	input;
	bool		addFlag = false;
	
	printPhoneBookHeader();
	while (input != "EXIT")
	{
		addFlag = false;
		if (!std::getline(std::cin, input))
		{
			std::cout << "Input stream closed, exiting phonebook.\n";
			break;
		}
		if (input == "ADD")
		{
			addFlag = true;
			if (phoneBook.addContact())
			{
				std::cout << "\nInput stream closed, exiting phonebook.\n";
				break;
			}
			printPhoneBookHeader();
		}
		if (input == "SEARCH")
			phoneBook.searchContact();
		else
		{
			if (!addFlag)
			{
				std::cout << "Error. Wrong Command, try again.\n";
				printPhoneBookHeader();
			}
		}
	}
	std::cout << "**PHONEBOOK EXITED**\n";
	return (0);
}
