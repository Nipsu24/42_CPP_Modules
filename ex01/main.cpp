/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:03:41 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/22 16:46:44 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;
	std::string	input;
	
	std::cout << "PhoneBook Options (Enter either of them):\n";
	std::cout << "ADD\n";
	std::cout << "SEARCH\n";
	std::cout << "EXIT\n";
	std::getline(std::cin, input);
	while (input != "EXIT")
	{
		// if (input == "ADD")
		// 	phoneBook.addContact();
		if (input == "s")
			phoneBook.searchContact();
		else
			std::cout << "Error. Wrong Command\n";
		std::getline(std::cin, input);
	}
	std::cout << "**EXITED PHONEBOOK**\n";
	return (0);
}
