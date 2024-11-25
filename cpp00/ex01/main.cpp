/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:03:41 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/25 15:42:04 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*Prints main menu of the phonebook, used throught the project
  in order to show to user which options are currently available.*/
static void	printPhoneBookHeader()
{
	std::cout << "*****************************************\n";
	std::cout << "PhoneBook Options (Enter either of them):\n";
	std::cout << "ADD\n";
	std::cout << "SEARCH\n";
	std::cout << "EXIT\n";
	std::cout << "*****************************************\n";
}

/*Reads user input and calls resprective phonebook functions for 
  adding or searching contacts. addFlag variable needed in order
  to avoid printing error message "wrong comman" also in cases
  where adding a contact was successful.*/
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
		{
			if (phoneBook.Count == 0)
			{
				std::cout << "\nNo contacts in phonebook.\n";
				printPhoneBookHeader();
			}
			else
				phoneBook.searchContact();
		}
		else
		{
			if (!addFlag)
			{
				if (input == "EXIT")
					break ; 
				std::cout << "Error. Wrong Command, try again.\n";
				printPhoneBookHeader();
			}
		}
	}
	std::cout << "**PHONEBOOK EXITED**\n";
	return (0);
}
