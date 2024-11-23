/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:03:41 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/23 12:53:08 by mmeier           ###   ########.fr       */
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
	
	printPhoneBookHeader();
	while (input != "EXIT")
	{
		if (!std::getline(std::cin, input))
		{
			std::cout << "Input stream closed, exiting phonebook.\n";
			break;
		}
		if (input == "ADD")
		{
			if (phoneBook.addContact())
			{
				std::cout << "\nInput stream closed, exiting phonebook.\n";
				break;
			}
		}
		if (input == "SEARCH")
			phoneBook.searchContact();
		else
		{
			std::cout << "Error. Wrong Command, try again.\n";
			printPhoneBookHeader();
		}
	}
	std::cout << "**PHONEBOOK EXITED**\n";
	return (0);
}
