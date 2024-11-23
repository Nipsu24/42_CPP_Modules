/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:03:41 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/23 11:53:59 by mmeier           ###   ########.fr       */
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
	std::getline(std::cin, input);
	while (input != "EXIT")
	{
		// if (input == "ADD")
		// 	phoneBook.addContact();
		if (input == "s")
			phoneBook.searchContact();
		else
		{
			std::cout << "Error. Wrong Command, try again.\n";
			printPhoneBookHeader();
		}
		std::getline(std::cin, input);
	}
	std::cout << "**EXITED PHONEBOOK**\n";
	return (0);
}
